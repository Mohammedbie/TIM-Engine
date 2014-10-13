#include "Move.h"
#include "HashKey.h"

/**************************************************************/
/* Captures , Pawn moves , and Castling  can't be repeated    */
/* so whenever there is one we should reset the fifty move    */
/* count and the repetition count.                            */
/**************************************************************/

void Make_Move(Board *board,Move *mov)
{
    /* Temporary Variables , for clearance and readability  */

    squares FROM,TO,Enpassent;
    pieces pc,Captured_pc,Promoted_pc;
    side Side_To_Move;
    castling Castling_Permissions;
    unsigned Full_Moves_Count,Fifty_Moves_Count,Repetition_Count;
    phase Game_Phase;
    U64 HashKey = board->Get_HashKey();
    char* Board_FEN;
    const Move* Last_Move;

    /* Extracting Move Info */

    FROM = squares(GET_FROM_SQUARE(mov->Info));
    pc = board->Get_Piece_onSquare(FROM);
    TO = squares(GET_TO_SQUARE(mov->Info));
    Side_To_Move = side(GET_SIDE_TO_PLAY(mov->Info));
    Captured_pc = pieces(GET_CAPTURED_PIECE(mov->Info));
    Promoted_pc = pieces(GET_PROMOTED_PIECE(mov->Info));
    Castling_Permissions = castling(GET_CASTLING_PERMISSIONS(mov->Info));
    Repetition_Count= GET_REPETITION_FROM_MOVE(mov->Info);
    Game_Phase = phase(GET_GAME_PHASE(mov->Info));

    /* Extracting Last Move */
    Last_Move = board->Get_Last_Move();

    /* Making the move */
    board->Set_Piece_onSquare(pc,TO);
    board->Clear_Square(FROM);

    //Hashing
    HashKey = Remove_Key_From_HashKey(PieceKeys[pc][FROM],HashKey);
    board->Inc_Fifty_Move_Count();
    if(Captured_pc != EMPTY)
    {
        HashKey = Remove_Key_From_HashKey(PieceKeys[Captured_pc][TO],HashKey);
        board->Set_IrreversiblePly_Index(board->Get_History_Size());

        board->Reset_Fify_Move_Count();
        board->Reset_Reptition_Count();
    }
    HashKey = Add_Key_To_HashKey(PieceKeys[pc][TO],HashKey);


    /* Updating Board Flags */
    board->Set_Enpassent(OFF_BOARD); //EnPassent square should be clear after each move.

    if(Side_To_Move == WHITE)
    {
        board->Set_Side_To_Move(BLACK);

        //Hashing
        HashKey = Add_Key_To_HashKey(BlackSideKey,HashKey);
    }
    else
    {
        board->Set_Side_To_Move(WHITE);
        board->Inc_Full_Moves_Count();
    }


    if(IS_PAWN_START(mov->Info))
    {
        Enpassent = GET_ENPASSENT_SQUARE(Side_To_Move,TO);
        board->Set_IrreversiblePly_Index(board->Get_History_Size());
        board->Set_Enpassent(Enpassent);
        board->Set_Game_Phase(OPEN_GAME);

        board->Reset_Fify_Move_Count();
        board->Reset_Reptition_Count();

        //Hashing
        HashKey = Add_Key_To_HashKey(EnpassentFileKeys[GET_FILE_FROM_SQUARE(Enpassent)],HashKey);
    }

    else if(Promoted_pc != EMPTY)
    {
        board->Set_Piece_onSquare(Promoted_pc,TO);
        board->Set_IrreversiblePly_Index(board->Get_History_Size());
        board->Set_Game_Phase(END_GAME);

        board->Reset_Fify_Move_Count();
        board->Reset_Reptition_Count();

        //Hashing
        HashKey = Remove_Key_From_HashKey(PieceKeys[Captured_pc][TO],HashKey);
        HashKey = Add_Key_To_HashKey(PieceKeys[Promoted_pc][TO],HashKey);
    }

    /* Castling */

    else if(Castling_Permissions != 0)
    {
        board->Set_IrreversiblePly_Index(board->Get_History_Size());
        if(Castling_Permissions == CastleWhiteKside || Castling_Permissions == CastleWhiteQside)
            Castling_Permissions = castling(CastleWhiteKside + CastleWhiteQside);
        else
            Castling_Permissions = castling(CastleBlackKside + CastleBlackQside);

        board->Set_Castling_Permissions((board->Get_Castling_Permissions()) - Castling_Permissions);
        if(Game_Phase != END_GAME)
        board->Set_Game_Phase(MID_GAME);

        board->Reset_Fify_Move_Count();
        board->Reset_Reptition_Count();

        //Hashing
        HashKey = Remove_Key_From_HashKey(CastlingKeys[Castling_Permissions],HashKey);
    }

    else if(pc == wR && FROM == a1)
    {
        board->Set_Castling_Permissions((board->Get_Castling_Permissions() | CastleWhiteQside) - CastleWhiteQside);
        if(Game_Phase == NONE || Game_Phase == OPEN_GAME)
            board->Set_Game_Phase(MID_GAME);

        //Hashing
        HashKey = Remove_Key_From_HashKey(CastlingKeys[CastleWhiteQside],HashKey);
    }

    else if(pc == wR && FROM == h1)
    {
        board->Set_Castling_Permissions((board->Get_Castling_Permissions() | CastleWhiteKside) - CastleWhiteKside);
        if(Game_Phase == NONE || Game_Phase == OPEN_GAME)
            board->Set_Game_Phase(MID_GAME);

        //Hashing
        HashKey = Remove_Key_From_HashKey(CastlingKeys[CastleWhiteKside],HashKey);
    }

    else if(pc == wK && FROM == e1)
    {
        board->Set_Castling_Permissions((board->Get_Castling_Permissions() | CastleWhiteQside | CastleWhiteKside) - CastleWhiteQside - CastleWhiteKside);
        board->Set_KingSq(WHITE,TO);

        if(Game_Phase == NONE ||Game_Phase == OPEN_GAME)
            board->Set_Game_Phase(MID_GAME);
        else
            board->Set_Game_Phase(END_GAME);

        //Hashing
        HashKey = Remove_Key_From_HashKey(CastlingKeys[CastleWhiteQside+CastleWhiteKside],HashKey);
    }

    else if(pc == bR && FROM == a8)
    {
        board->Set_Castling_Permissions((board->Get_Castling_Permissions() | CastleBlackQside) - CastleBlackQside);
        if(Game_Phase == NONE ||Game_Phase == OPEN_GAME)
            board->Set_Game_Phase(MID_GAME);

        //Hashing
        HashKey = Remove_Key_From_HashKey(CastlingKeys[CastleBlackQside],HashKey);
    }

    else if(pc == bR && FROM == h8)
    {
        board->Set_Castling_Permissions((board->Get_Castling_Permissions() | CastleBlackKside) - CastleBlackKside);
        if(Game_Phase == NONE ||Game_Phase == OPEN_GAME)
            board->Set_Game_Phase(MID_GAME);

        //Hashing
        HashKey = Remove_Key_From_HashKey(CastlingKeys[CastleBlackKside],HashKey);
    }

    else if(pc == bK && FROM == e8)
    {
        board->Set_Castling_Permissions((board->Get_Castling_Permissions() | CastleBlackQside | CastleBlackKside) - CastleBlackQside - CastleBlackKside);
        board->Set_KingSq(BLACK,TO);

        if(Game_Phase == NONE ||Game_Phase == OPEN_GAME)
            board->Set_Game_Phase(MID_GAME);
        else
            board->Set_Game_Phase(END_GAME);

        //Hashing
        HashKey = Remove_Key_From_HashKey(CastlingKeys[CastleBlackQside+CastleBlackKside],HashKey);
    }

    board->Set_HashKey(HashKey);

    if(Last_Move != new Move())
    {
        if(Last_Move->HashKey == HashKey){ std::cout << "HI \n\n";
            board->Inc_Repetition_Count();}
    }
    else
        delete Last_Move;

    mov->HashKey = HashKey;
    board->Add_Move_To_History(mov);



}

