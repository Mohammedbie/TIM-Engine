#include "Move.h"
#include "HashKey.h"

/****************************************************************/
/* Captures , Pawn moves , and Castling  can't be repeated      */
/* so whenever there is one we should reset the fifty move      */
/* count and point the IrreversiblePly index to this move .     */
/****************************************************************/

void Make_Move(Board *board,Move *mov)
{
     if(board->Get_Fify_Move_Count() == 50)
        std::cout << "Draw by Fifty move rule.\n\n";

    /* Temporary Variables , for clearance and readability  */

    squares FROM,TO,Enpassent;
    pieces pc,Captured_pc,Promoted_pc;
    side Side_To_Move;
    unsigned Castling_Permissions,History_Size;
    phase Game_Phase;
    char* Board_FEN;
    U64 HashKey;

    /* Extracting Move Info */

    FROM = squares(GET_FROM_SQUARE(mov->Info));
    TO = squares(GET_TO_SQUARE(mov->Info));
    Side_To_Move = side(GET_SIDE_TO_PLAY(mov->Info));
    Captured_pc = pieces(GET_CAPTURED_PIECE(mov->Info));
    Promoted_pc = pieces(GET_PROMOTED_PIECE(mov->Info));
    Castling_Permissions = GET_CASTLING_PERMISSIONS(mov->Info);
    Game_Phase = phase(GET_GAME_PHASE(mov->Info));

    /* Extracting Board Info */
    pc = board->Get_Piece_onSquare(FROM);
    History_Size = board->Get_History_Size();
    HashKey = board->Get_HashKey();

    /* Changing move flags to be able to UNDO move */
    SET_CASTLING_PERMISSIONS(mov->Info,board->Get_Castling_Permissions());
    SET_GAME_PHASE(mov->Info,board->Get_Game_Phase());

    /* Making the move */
    board->Set_Piece_onSquare(pc,TO);
    board->Clear_Square(FROM);

    //Hashing
    HashKey = Remove_Key_From_HashKey(PieceKeys[pc][FROM],HashKey);
    std::cout << "MAKE_MOVE KEYS : \n\n";
    std::cout << "Removed Key : " << std::hex << PieceKeys[pc][FROM] << "\n";
    board->Inc_Fifty_Move_Count();
    if(Captured_pc != EMPTY)
    {
        HashKey = Remove_Key_From_HashKey(PieceKeys[Captured_pc][TO],HashKey);
        std::cout << "Removed Key : " << std::hex << PieceKeys[Captured_pc][TO] << "\n";
        board->Set_IrreversiblePly_Index(History_Size);

        board->Reset_Fify_Move_Count();
    }
    HashKey = Add_Key_To_HashKey(PieceKeys[pc][TO],HashKey);
    std::cout << "Added Key : " << std::hex << PieceKeys[pc][TO] << "\n";


    /* Updating Board Flags */
    board->Set_Enpassent(OFF_BOARD); //EnPassent square should be clear after each move.

    if(Side_To_Move == WHITE)
    {
        board->Set_Side_To_Move(BLACK);

        //Hashing
        HashKey = Add_Key_To_HashKey(BlackSideKey,HashKey);
        std::cout << "Added Key : " << std::hex << BlackSideKey << "\n";
    }
    else
    {
        board->Set_Side_To_Move(WHITE);
        board->Inc_Full_Moves_Count();
    }

    /* Pawn moves */
    if(pc == wP || pc == bP)
    {
        board->Set_IrreversiblePly_Index(History_Size);
        board->Reset_Fify_Move_Count();

        if(IS_PAWN_START(mov->Info))
        {
             Enpassent = GET_ENPASSENT_SQUARE(Side_To_Move,TO);
             board->Set_Enpassent(Enpassent);
             board->Set_Game_Phase(OPEN_GAME);

            //Hashing
            HashKey = Add_Key_To_HashKey(EnpassentFileKeys[GET_FILE_FROM_SQUARE(Enpassent)],HashKey);
            std::cout << "Added Key : " << std::hex << EnpassentFileKeys[GET_FILE_FROM_SQUARE(Enpassent)] << "\n";
        }

        else if(Promoted_pc != EMPTY)
        {
            board->Set_Piece_onSquare(Promoted_pc,TO);
            board->Set_Game_Phase(END_GAME);

            //Hashing
            HashKey = Remove_Key_From_HashKey(PieceKeys[Captured_pc][TO],HashKey);
            std::cout << "Removed Key : " << std::hex << PieceKeys[Captured_pc][TO] << "\n";
            HashKey = Add_Key_To_HashKey(PieceKeys[Promoted_pc][TO],HashKey);
            std::cout << "Removed Key : " << std::hex << PieceKeys[Promoted_pc][TO] << "\n";
        }

    }


    /* Castling */

    else if(Castling_Permissions != 0)
    {
        board->Set_IrreversiblePly_Index(History_Size);

        if(Castling_Permissions == CastleWhiteKside || Castling_Permissions == CastleWhiteQside)
            Castling_Permissions = CastleWhiteKside + CastleWhiteQside;
        else
            Castling_Permissions = CastleBlackKside + CastleBlackQside;

        board->Set_Castling_Permissions((board->Get_Castling_Permissions()) - Castling_Permissions);
        if(Game_Phase != END_GAME)
        board->Set_Game_Phase(MID_GAME);

        board->Reset_Fify_Move_Count();

        //Hashing
        HashKey = Remove_Key_From_HashKey(CastlingKeys[Castling_Permissions],HashKey);
        std::cout << "Removed Key : " << std::hex << CastlingKeys[Castling_Permissions] << "\n";
    }

    else if(pc == wR && FROM == a1)
    {
        board->Set_Castling_Permissions((board->Get_Castling_Permissions() | CastleWhiteQside) - CastleWhiteQside);
        if(Game_Phase == NONE || Game_Phase == OPEN_GAME)
            board->Set_Game_Phase(MID_GAME);

        //Hashing
        HashKey = Remove_Key_From_HashKey(CastlingKeys[CastleWhiteQside],HashKey);
        std::cout << "Removed Key : " << std::hex << CastlingKeys[CastleWhiteQside] << "\n";
    }

    else if(pc == wR && FROM == h1)
    {
        board->Set_Castling_Permissions((board->Get_Castling_Permissions() | CastleWhiteKside) - CastleWhiteKside);
        if(Game_Phase == NONE || Game_Phase == OPEN_GAME)
            board->Set_Game_Phase(MID_GAME);

        //Hashing
        HashKey = Remove_Key_From_HashKey(CastlingKeys[CastleWhiteKside],HashKey);
        std::cout << "Removed Key : " << std::hex << CastlingKeys[CastleWhiteKside] << "\n";
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
        std::cout << "Removed Key : " << std::hex << CastlingKeys[CastleWhiteQside+CastleWhiteKside] << "\n";
    }

    else if(pc == bR && FROM == a8)
    {
        board->Set_Castling_Permissions((board->Get_Castling_Permissions() | CastleBlackQside) - CastleBlackQside);
        if(Game_Phase == NONE ||Game_Phase == OPEN_GAME)
            board->Set_Game_Phase(MID_GAME);

        //Hashing
        HashKey = Remove_Key_From_HashKey(CastlingKeys[CastleBlackQside],HashKey);
        std::cout << "Removed Key : " << std::hex << CastlingKeys[CastleBlackQside] << "\n";
    }

    else if(pc == bR && FROM == h8)
    {
        board->Set_Castling_Permissions((board->Get_Castling_Permissions() | CastleBlackKside) - CastleBlackKside);
        if(Game_Phase == NONE ||Game_Phase == OPEN_GAME)
            board->Set_Game_Phase(MID_GAME);

        //Hashing
        HashKey = Remove_Key_From_HashKey(CastlingKeys[CastleBlackKside],HashKey);
        std::cout << "Removed Key : " << std::hex << CastlingKeys[CastleBlackKside] << "\n";
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
        std::cout << "Removed Key : " << std::hex << CastlingKeys[CastleBlackQside+CastleBlackKside] << "\n";
    }

    if(History_Size != board->Get_IrreversiblePly_Index() && History_Size > 3)
        if(board->Is_3Repetition_Draw(HashKey))
            std::cout << "Draw by 3-Fold Repetition after " << Squares_Name[FROM] << "-" << Squares_Name[TO] << ".\n\n";

    board->Set_HashKey(HashKey);
    mov->HashKey = HashKey;
    board->Add_Move_To_History(mov);
}

// Note : STILL NEEDS TO RESTORE IRREVERSIBLE_INDEX AND FIFTY_MOVE_COUNT
void UNDO_Move(Board* board)
{
    const Move* mov;

    /* Temporary Variables , for clearance and readability  */

    squares FROM,TO,Enpassent;
    pieces pc,Captured_pc,Promoted_pc;
    side Side_To_Move;
    unsigned Castling_Permissions;
    phase Game_Phase;
    char* Board_FEN;
    U64 HashKey;

    if(board->Get_History_Size() != 0)
    {
        mov = board->Get_Last_Move();
        board->Pop_Last_Move();

       /* Extracting Move Info */

       FROM = squares(GET_FROM_SQUARE(mov->Info));
       TO = squares(GET_TO_SQUARE(mov->Info));
       Side_To_Move = side(GET_SIDE_TO_PLAY(mov->Info));
       Captured_pc = pieces(GET_CAPTURED_PIECE(mov->Info));
       Promoted_pc = pieces(GET_PROMOTED_PIECE(mov->Info));
       Castling_Permissions = GET_CASTLING_PERMISSIONS(mov->Info);
       Game_Phase = phase(GET_GAME_PHASE(mov->Info));

       /* Extracting board Info */
       HashKey = board->Get_HashKey();

       /* Restoring Board flags */

        std::cout << "UNDO_MOVE KEYS : " << "\n\n";
       //Hashing
       if(Castling_Permissions != 0) //This move was castling move.
       {
           std::cout << "Added Key : " << std::hex << CastlingKeys[CastleBlackQside+CastleBlackKside] << "\n";
           if(Castling_Permissions == CastleBlackKside || Castling_Permissions == CastleBlackQside)
               Add_Key_To_HashKey(CastlingKeys[CastleBlackQside + CastleBlackKside],HashKey);
           else
               Add_Key_To_HashKey(CastlingKeys[CastleWhiteQside + CastleWhiteKside],HashKey);
       }
       board->Set_Castling_Permissions((board->Get_Castling_Permissions() + Castling_Permissions));
       board->Set_Game_Phase(Game_Phase);
       board->Dec_Full_Move_Count();

       /* Extracting Board Info */

       pc = board->Get_Piece_onSquare(TO);


       /* UNDO the move */
       if(Promoted_pc == EMPTY) //There was no promotion
           board->Set_Piece_onSquare(pc,FROM);
       else
        if(Side_To_Move == WHITE)
            board->Set_Piece_onSquare(wP,FROM);
        else
            board->Set_Piece_onSquare(bP,FROM);

       board->Clear_Square(TO);

       //Hashing
       HashKey = Remove_Key_From_HashKey(PieceKeys[pc][TO],HashKey);
       std::cout << "Removed Key : " << std::hex << PieceKeys[pc][TO] << "\n";

       board->Dec_Fifty_Move_Count();
       if(Captured_pc != EMPTY)
       {
           board->Set_Piece_onSquare(Captured_pc,TO);

           HashKey = Add_Key_To_HashKey(PieceKeys[Captured_pc][TO],HashKey);
           std::cout << "Added Key : " << std::hex << PieceKeys[Captured_pc][TO] << "\n";

          /* board->Set_IrreversiblePly_Index(History_Size);
           board->Reset_Fify_Move_Count();*/
       }
       HashKey = Add_Key_To_HashKey(PieceKeys[pc][FROM],HashKey);
       std::cout << "Added Key : " << std::hex << PieceKeys[pc][FROM] << "\n";

       if(Side_To_Move == BLACK)
       {
           board->Set_Side_To_Move(BLACK);

       }
       else
       {
           board->Set_Side_To_Move(WHITE);
           board->Dec_Full_Move_Count();

           //Hashing
           HashKey = Remove_Key_From_HashKey(BlackSideKey,HashKey);
           std::cout << "Removed Key : " << std::hex << BlackSideKey << "\n";
       }

       //Restoring EnPassent square, if any.
       if(board->Get_History_Size() != 0) //there was a move before this one.
       {
           const Move* tempMov = board->Get_Last_Move();
           if(IS_PAWN_START(tempMov->Info))
           {
               Enpassent = GET_ENPASSENT_SQUARE(1-Side_To_Move,GET_TO_SQUARE(tempMov->Info)); //Reverse side
               board->Set_Enpassent(Enpassent);
           }
       }

       board->Set_HashKey(HashKey);

    }

}
