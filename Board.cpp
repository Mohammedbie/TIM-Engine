/*

*/
#include <iostream>

#include "Board.h"

Board :: Board()
{
    Init_Board();
    Display_Board();
}

bool Board::Init_Board()
{
    Board::Init_Board_Pieces();
    Board::Init_Board_Flags();
}

bool Board::Init_Board_Pieces()
{
    White_Pawns = White_Knights = White_Bishops = White_Rooks = White_Queens = White_King = White_Pieces = 0;
    Black_Pawns = Black_Knights = Black_Bishops = Black_Rooks = Black_Queens = Black_King = Black_Pieces = 0;
    All_Pieces = 0;

    for(unsigned i=0; i<64; ++i)
    {
        Piece_Type_By_Square[i] = EMPTY;
    }
}

bool Board::Init_Board_Flags()
{
    Side_To_Move = ANY;
    Enpassent = OFF_BOARD;
    Full_Moves_Count = Fify_Move_Count = Repetition_Count = HashKey = 0;
    Castling_Permissions = UNKNOWN;
    Game_Phase = NONE;
    History.reserve(AVERAGE_GAME_MOVES);

    Board_FEN = nullptr; //can be changed to "NULL" for c++ backward compatibility
}

void Board::Display_Board()
{
    U64 AND_temp = 1;

    std::cout << "   a b c d e f g h\n";

    for(unsigned i = 0; i < 64 ; i++ )
    {
        if(i%8 == 0)
            std::cout << "\n" << i/8 + 1 << "  ";

        if(All_Pieces & AND_temp)
        {
            if(Piece_Type_By_Square[i] == wP)
                std::cout << "P ";
            else if(Piece_Type_By_Square[i] == wN)
                std::cout << "N ";
            else if(Piece_Type_By_Square[i] == wB)
                std::cout << "B ";
            else if(Piece_Type_By_Square[i] == wR)
                std::cout << "R ";
            else if(Piece_Type_By_Square[i] == wQ)
                std::cout << "Q ";
            else if(Piece_Type_By_Square[i] == wK)
                std::cout << "K ";

            else if(Piece_Type_By_Square[i] == bP)
                std::cout << "p ";
            else if(Piece_Type_By_Square[i] == bN)
                std::cout << "n ";
            else if(Piece_Type_By_Square[i] == bB)
                std::cout << "b ";
            else if(Piece_Type_By_Square[i] == bR)
                std::cout << "r ";
            else if(Piece_Type_By_Square[i] == bQ)
                std::cout << "q ";
            else if(Piece_Type_By_Square[i] == bK)
                std::cout << "k ";
        }
        else
            std::cout << "- ";

        AND_temp = AND_temp << 1;

    }

    std::cout << "\n\nSide to move : ";

    if(Side_To_Move == WHITE)
        std::cout << "white.\n";
    else if(Side_To_Move == BLACK)
        std::cout << "black.\n";
    else if(Side_To_Move == ANY)
        std::cout << "ANY.\n";
    else
        std::cout << "Wrong value, find the bug!!!\n";

    std::cout << "Full moves count = " << Full_Moves_Count << "\n";
    std::cout << "FiftyMove count = " << Fify_Move_Count << "\n";


    std::cout << "Castling Permissions : ";

    if(Castling_Permissions & CastleWhiteKside)
        std::cout << "K";
    if(Castling_Permissions & CastleWhiteQside)
        std::cout << "Q";
    if(Castling_Permissions & CastleBlackKside)
        std::cout << "k";
    if(Castling_Permissions & CastleBlackQside)
        std::cout << "q";
    if(Castling_Permissions & UNKNOWN)
        std::cout << "-";

    std::cout << "\nEnpassent square : " << Squares_Name[Enpassent];

    std::cout << "\nRepetition count = " << Repetition_Count << "\n";
    std::cout << std::hex << "Board hash key = " << HashKey << std::dec << "\n";
    std::cout << "\nFEN : ";

    if(Board_FEN == nullptr)
        std::cout << "NULL\n\n";
    else
    {
        for(unsigned i = 0; Board_FEN[i] != '\0'; i++)
        {
            std::cout << Board_FEN[i];
        }
        std::cout << "\n\n";
    }

}

bool Board::Set_Piece_onSquare(pieces pc, squares sq)
{

    switch(pc)
    {

    case wP:

        White_Pawns |= SET_SQUARE(sq);
        White_Pieces |= SET_SQUARE(sq);
        Piece_Type_By_Square[sq] = wP;
        break;

    case wN:
        White_Knights |= SET_SQUARE(sq);
        White_Pieces |= SET_SQUARE(sq);
        Piece_Type_By_Square[sq] = wN;
        break;

    case wB:
        White_Bishops |= SET_SQUARE(sq);
        White_Pieces |= SET_SQUARE(sq);
        Piece_Type_By_Square[sq] = wB;
        break;

    case wR:
        White_Rooks |= SET_SQUARE(sq);
        White_Pieces |= SET_SQUARE(sq);
        Piece_Type_By_Square[sq] = wR;
        break;

    case wQ:
        White_Queens |= SET_SQUARE(sq);
        White_Pieces |= SET_SQUARE(sq);
        Piece_Type_By_Square[sq] = wQ;
        break;

    case wK:
        White_King |= SET_SQUARE(sq);
        White_Pieces |= SET_SQUARE(sq);
        Piece_Type_By_Square[sq] = wK;
        KingSquare[WHITE] = sq;
        break;

    case bP:
        Black_Pawns |= SET_SQUARE(sq);
        Black_Pieces |= SET_SQUARE(sq);
        Piece_Type_By_Square[sq] = bP;
        break;

    case bN:
        Black_Knights |= SET_SQUARE(sq);
        Black_Pieces |= SET_SQUARE(sq);
        Piece_Type_By_Square[sq] = bN;
        break;

    case bB:
        Black_Bishops |= SET_SQUARE(sq);
        Black_Pieces |= SET_SQUARE(sq);
        Piece_Type_By_Square[sq] = bB;
        break;

    case bR:
        Black_Rooks |= SET_SQUARE(sq);
        Black_Pieces |= SET_SQUARE(sq);
        Piece_Type_By_Square[sq] = bR;
        break;

    case bQ:
        Black_Queens |= SET_SQUARE(sq);
        Black_Pieces |= SET_SQUARE(sq);
        Piece_Type_By_Square[sq] = bQ;
        break;

    case bK:
        Black_King |= SET_SQUARE(sq);
        Black_Pieces |= SET_SQUARE(sq);
        Piece_Type_By_Square[sq] = bK;
        KingSquare[BLACK] = sq;
        break;

    default:
        return false;

    }

    All_Pieces  |= SET_SQUARE(sq);
    return true;
}

pieces Board::Get_Piece_onSquare(squares sq) const
{
    return Piece_Type_By_Square[sq];
}


bool Board::Clear_Square(squares sq)
{
    U64 Board_temp = 1;
    Board_temp = Board_temp << sq;
    Board_temp = ~Board_temp;

    All_Pieces &= Board_temp;

    if(Piece_Type_By_Square[sq] >= wP && Piece_Type_By_Square[sq] <= wQ)
        White_Pieces &= Board_temp;
    else if(Piece_Type_By_Square[sq] > wK && Piece_Type_By_Square[sq] < bK)
        Black_Pieces &= Board_temp;

    if(Piece_Type_By_Square[sq] == wP)
        White_Pawns &= Board_temp;
    else if(Piece_Type_By_Square[sq] == wN)
        White_Knights &= Board_temp;
    else if(Piece_Type_By_Square[sq] == wB)
        White_Bishops &= Board_temp;
    else if(Piece_Type_By_Square[sq] == wR)
        White_Rooks &= Board_temp;
    else if(Piece_Type_By_Square[sq] == wQ)
        White_Queens &= Board_temp;
    else if(Piece_Type_By_Square[sq] == wK) //Illegal move: tried to remove the white king!!
        return false;

    else if(Piece_Type_By_Square[sq] == bP)
        Black_Pawns &= Board_temp;
    else if(Piece_Type_By_Square[sq] == bN)
        Black_Knights &= Board_temp;
    else if(Piece_Type_By_Square[sq] == bB)
        Black_Bishops &= Board_temp;
    else if(Piece_Type_By_Square[sq] == bR)
        Black_Rooks &= Board_temp;
    else if(Piece_Type_By_Square[sq] == bQ)
        Black_Queens &= Board_temp;
    else if(Piece_Type_By_Square[sq] == bK) //Illegal move: tried to remove the black king!!
        return false;

    else if(Piece_Type_By_Square[sq] == EMPTY); //do nothing
    else
        return false;

    return true;

}

unsigned Board::Get_Piece_Count(pieces pc) const
{
    unsigned cnt=0;
    U64 board;

        /* White pieces */

        if(pc == wP)
            board = White_Pawns;

        else if(pc == wN)
            board = White_Knights;

        else if(pc == wB)
            board = White_Bishops;

        else if(pc == wR)
            board = White_Rooks;

        else if(pc == wQ)
            board = White_Queens;

        else if(pc == wK)
            board = White_King;

        else if(pc == EMPTY)
            board = ~All_Pieces;


        /* Black pieces */

        else if(pc == bP)
            board = Black_Pawns;

        else if(pc == bN)
            board = Black_Knights;

        else if(pc == bB)
            board = Black_Bishops;

        else if(pc == bR)
            board = Black_Rooks;

        else if(pc == bQ)
            board = Black_Queens;

        else if(pc == bK)
            board = Black_King;



        else if(pc == EMPTY)
            board = ~All_Pieces;

        else if(pc == ALL)
            board = All_Pieces;

        else
            return INVAILD;


    while(board)
    {
        cnt++;
        board &= board-1;
    }

    return cnt;

}

bool Board::Set_Side_To_Move(side s)
{
    if(s == WHITE || s == BLACK || s == ANY)
        Side_To_Move = s;

    else
        return false;

    return true;
}

side Board::Get_Side_To_Move() const
{
    return Side_To_Move;
}

void Board::Set_Enpassent(squares sq)
{
    Enpassent = sq;
}

squares Board::Get_Enpassent() const
{
    return Enpassent;
}

void Board::Set_KingSq(side s,squares sq)
{
    if(s == WHITE && sq != OFF_BOARD)
        KingSquare[0] == sq;
    else if(s == BLACK && sq != OFF_BOARD)
        KingSquare[1] == sq;
}

squares Board::Get_KingSq(pieces pc) const
{
    if(pc == wK)
        return KingSquare[0];
    else if(pc == bK)
        return KingSquare[1];
}

bool Board::Set_Full_Moves_Count(unsigned cnt)
{
    if(cnt < INVAILD)
        Full_Moves_Count = cnt;

    else
        return false;

    return true;
}

void Board::Inc_Full_Moves_Count()
{
    Full_Moves_Count++;
}

unsigned Board::Get_Full_Moves_Count() const
{
   return Full_Moves_Count < INVAILD ?  Full_Moves_Count :  INVAILD;
}

bool Board::Set_Castling_Permissions(unsigned cas)
{
    if(cas <= UNKNOWN)
        Castling_Permissions = cas;
    else
        return false;

    return true;
}

unsigned Board::Get_Castling_Permissions() const
{
    if(Castling_Permissions <= UNKNOWN)
        return Castling_Permissions;

    else
        return INVAILD;
}

bool Board::Set_Fify_Move_Count(unsigned cnt)
{
    if(cnt < INVAILD)
        Fify_Move_Count = cnt;
    else
        return false;

    return true;
}

void Board::Inc_Fifty_Move_Count()
{
    Fify_Move_Count++;
}

unsigned Board::Get_Fify_Move_Count() const
{
    if(Fify_Move_Count < INVAILD)
        return Fify_Move_Count;
    else
        return INVAILD;
}

void Board::Reset_Fify_Move_Count()
{
    Fify_Move_Count = 0;
}

void Board::Set_Board_FEN(char* FEN , unsigned Length)
{
        Board_FEN = FEN;
}

char* Board::Get_Board_FEN() const
{
    return Board_FEN;
}

bool Board::Set_Game_Phase(phase p)
{
    if(p == OPEN_GAME || p == MID_GAME || p == END_GAME || p == NONE)
        Game_Phase = p;
    else
        return false;

    return true;
}

phase Board::Get_Game_Phase() const
{
        return Game_Phase;
}

void Board::Set_IrreversiblePly_Index(unsigned index)
{
    Last_Irreversible_ply_index = index;
}

unsigned Board::Get_IrreversiblePly_Index()
{
    return Last_Irreversible_ply_index;
}

void Board::Set_HashKey(U64 key)
{
    HashKey = key;
}

U64 Board::Get_HashKey() const
{
    return HashKey;
}

void Board::Inc_Repetition_Count()
{
    Repetition_Count++;
}

void Board::Reset_Reptition_Count()
{
    Repetition_Count = 0;
}

unsigned Board::Get_Repetition_Count() const
{
    return Repetition_Count;
}

void Board::Add_Move_To_History(const Move *mv)
{
    History.push_back(mv);
}

const Move* Board::Get_Last_Move() const
{
    if(History.size() > 1)
        return History[(History.size())-2];
    else
        return new Move;
}

unsigned Board::Get_History_Size()
{
    return History.size();
}

void Board::Pop_Last_Move()
{
    if(!History.empty())
       History.pop_back();
}

bool Board::Is_Square_Attacked(squares sq,side s) const
{

    if(s == WHITE)
    {
        if(White_Pawns & Black_Pawn_Direct_Attacks[sq])
            return true;
        if(White_Knights & Knight_Moves[sq])
            return true;
        if(White_Bishops & Bishop_Moves[sq])
            return true;
        if(White_Rooks & Rook_Moves[sq])
            return true;
        if(White_Queens & Queen_Moves[sq])
            return true;
        if(White_King & King_Moves[sq])
            return true;
    }

    else if(s == BLACK)
    {
        if(Black_Pawns & White_Pawn_Direct_Attacks[sq])
            return true;
        if(Black_Knights & Knight_Moves[sq])
            return true;
        if(Black_Bishops & Bishop_Moves[sq])
            return true;
        if(Black_Rooks & Rook_Moves[sq])
            return true;
        if(Black_Queens & Queen_Moves[sq])
            return true;
        if(Black_King & King_Moves[sq])
            return true;
    }

    else if(s == ANY)
    {
        if(Is_Square_Attacked(sq,WHITE))
            return true;
        else
            return Is_Square_Attacked(sq,BLACK);
    }

    else
        return false;
}

bool Board::Is_Square_Attacked_By_Piece(squares sq,pieces pc) const
{
    switch(pc)
    {
        case wP:
        if(White_Pawns & Black_Pawn_Direct_Attacks[sq])
        return true;

        case wN:
        if(White_Knights & Knight_Moves[sq])
        return true;

        case wB:
        if(White_Bishops & Bishop_Moves[sq])
        return true;

        case wR:
        if(White_Rooks & Rook_Moves[sq])
        return true;

        case wQ:
        if(White_Queens & Queen_Moves[sq])
        return true;

        case wK:
        if(White_King & King_Moves[sq])
        return true;


        case bP:
        if(Black_Pawns & Black_Pawn_Direct_Attacks[sq])
        return true;

        case bN:
        if(Black_Knights & Knight_Moves[sq])
        return true;

        case bB:
        if(Black_Bishops & Bishop_Moves[sq])
        return true;

        case bR:
        if(Black_Rooks & Rook_Moves[sq])
        return true;

        case bQ:
        if(Black_Queens & Queen_Moves[sq])
        return true;

        case bK:
        if(Black_King & King_Moves[sq])
        return true;

        default:
        return false;
    }

}

void Board::Get_Possible_Moves_By_Piece_Type(Possible_Moves* Moves,pieces pc) const
{
    U64 And_Result;

    //If the side with this piece under check , DO NOTHING , in MakeMove we will check the king is still under check.
    if(GET_PIECE_COLOUR(pc) == WHITE && Is_Square_Attacked(KingSquare[WHITE],BLACK));
    else if(GET_PIECE_COLOUR(pc) == BLACK && Is_Square_Attacked(KingSquare[BLACK],WHITE));

    //White Pawn moves
    else if(pc == wP)
    {

        for(unsigned sq=0;sq<64;++sq)
        {
            if(Piece_Type_By_Square[sq] == wP)
            {
                //Direct Captures
                And_Result = White_Pawn_Direct_Attacks[sq] & Black_Pieces;


                if(And_Result != 0)
                 {
                     std::vector<unsigned int> TO_sqs;
                     Get_SetBits_Indecies(TO_sqs,And_Result);

                     for(unsigned i=0;i<TO_sqs.size();++i)
                     {
                         //Promotion Moves
                         if(GET_RANK_FROM_SQUARE(sq) == Rank_7)
                         {
                             Set_Move_Info((Moves->moves)+(Moves->Count++),sq,TO_sqs[i],wN,Piece_Type_By_Square[TO_sqs[i]],0,0,Game_Phase,false,Side_To_Move,false);
                             Set_Move_Info((Moves->moves)+(Moves->Count++),sq,TO_sqs[i],wB,Piece_Type_By_Square[TO_sqs[i]],0,0,Game_Phase,false,Side_To_Move,false);
                             Set_Move_Info((Moves->moves)+(Moves->Count++),sq,TO_sqs[i],wR,Piece_Type_By_Square[TO_sqs[i]],0,0,Game_Phase,false,Side_To_Move,false);
                             Set_Move_Info((Moves->moves)+(Moves->Count),sq,TO_sqs[i],wQ,Piece_Type_By_Square[TO_sqs[i]],0,0,Game_Phase,false,Side_To_Move,false);

                         }

                         else
                         Set_Move_Info((Moves->moves)+(Moves->Count),sq,TO_sqs[i],EMPTY,Piece_Type_By_Square[TO_sqs[i]],0,0,Game_Phase,false,Side_To_Move,false);

                         Moves->Count++;

                     }
                 }

                 //EnPassent Capture
                 And_Result = (U64(1)<<Enpassent) & White_Pawn_Direct_Attacks[sq];
                 if(GET_RANK_FROM_SQUARE(sq) == Rank_5 && And_Result!= 0)
                 {
                     Set_Move_Info((Moves->moves)+(Moves->Count),sq,Enpassent,EMPTY,bP,0,0,Game_Phase,true,Side_To_Move,false);
                     Moves->Count++;
                 }

                 //Quiet Moves
                 if(Piece_Type_By_Square[sq+8] == EMPTY)
                 {
                     //Pawn Start
                     if(GET_RANK_FROM_SQUARE(sq) == Rank_2  && Piece_Type_By_Square[sq+16] == EMPTY )
                     {
                         Set_Move_Info((Moves->moves)+(Moves->Count),sq,sq+16,EMPTY,EMPTY,0,0,Game_Phase,false,Side_To_Move,true);
                         Moves->Count++;
                     }


                         Set_Move_Info((Moves->moves)+(Moves->Count),sq,sq+8,EMPTY,EMPTY,0,0,Game_Phase,false,Side_To_Move,false);
                         Moves->Count++;
                 }



            }
        }
    }

    //Black Pawn moves
    else if(pc == bP)
    {
        for(unsigned sq=0;sq<64;++sq)
        {
            if(Piece_Type_By_Square[sq] == bP)
            {
                //Direct Captures
                U64 And_Result = Black_Pawn_Direct_Attacks[sq] & White_Pieces;


                if(And_Result != 0)
                 {
                     std::vector<unsigned int> TO_sqs;
                     Get_SetBits_Indecies(TO_sqs,And_Result);

                     for(unsigned i=0;i<TO_sqs.size();++i)
                     {
                         if(GET_RANK_FROM_SQUARE(sq) == Rank_2)
                         {
                             //Promotion Moves
                             Set_Move_Info((Moves->moves)+(Moves->Count++),sq,TO_sqs[i],bN,Piece_Type_By_Square[TO_sqs[i]],0,0,Game_Phase,false,Side_To_Move,false);
                             Set_Move_Info((Moves->moves)+(Moves->Count++),sq,TO_sqs[i],bB,Piece_Type_By_Square[TO_sqs[i]],0,0,Game_Phase,false,Side_To_Move,false);
                             Set_Move_Info((Moves->moves)+(Moves->Count++),sq,TO_sqs[i],bR,Piece_Type_By_Square[TO_sqs[i]],0,0,Game_Phase,false,Side_To_Move,false);
                             Set_Move_Info((Moves->moves)+(Moves->Count),sq,TO_sqs[i],bQ,Piece_Type_By_Square[TO_sqs[i]],0,0,Game_Phase,false,Side_To_Move,false);

                         }

                         else
                         Set_Move_Info((Moves->moves)+(Moves->Count),sq,TO_sqs[i],EMPTY,Piece_Type_By_Square[TO_sqs[i]],0,0,Game_Phase,false,Side_To_Move,false);

                         Moves->Count++;

                     }
                 }

                 //EnPassent Capture
                 And_Result = (U64(1)<<Enpassent) & Black_Pawn_Direct_Attacks[sq];
                 if(GET_RANK_FROM_SQUARE(sq) == Rank_4 && And_Result!= 0)
                 {
                     Set_Move_Info((Moves->moves)+(Moves->Count),sq,Enpassent,EMPTY,wP,0,0,Game_Phase,true,Side_To_Move,false);
                     Moves->Count++;
                 }

                 //Quiet Moves
                 if(Piece_Type_By_Square[sq-8] == EMPTY)
                 {
                     //Pawn Start
                     if(GET_RANK_FROM_SQUARE(sq) == Rank_7  && Piece_Type_By_Square[sq-16] == EMPTY )
                     {
                         Set_Move_Info((Moves->moves)+(Moves->Count),sq,sq-16,EMPTY,EMPTY,0,0,Game_Phase,false,Side_To_Move,true);
                         Moves->Count++;
                     }


                         Set_Move_Info((Moves->moves)+(Moves->Count),sq,sq-8,EMPTY,EMPTY,0,0,Game_Phase,false,Side_To_Move,false);
                         Moves->Count++;
                 }



            }
        }
    }

    //Knights moves
    else if(pc == wN || pc == bN)
    {
        for(unsigned sq=0;sq<64;++sq)
        {
            if(Piece_Type_By_Square[sq] == pc)
            {
                if(pc == wN)
                And_Result = (Knight_Moves[sq] | White_Pieces) ^ White_Pieces;
                else
                And_Result = (Knight_Moves[sq] | Black_Pieces) ^ Black_Pieces;

                if(And_Result != 0)
                {
                    std::vector<unsigned int> TO_sqs;
                    Get_SetBits_Indecies(TO_sqs,And_Result);

                    for(unsigned i=0;i<TO_sqs.size();++i)
                    {
                        Set_Move_Info((Moves->moves)+(Moves->Count),sq,TO_sqs[i],EMPTY,Piece_Type_By_Square[TO_sqs[i]],0,0,Game_Phase,false,Side_To_Move,false);
                        Moves->Count++;
                    }

                }
            }
        }

    }

    //Bishops moves
    else if(pc == wB || pc == bB)
    {
        for(squares sq=a1;sq<OFF_BOARD;sq = squares(sq+b1))
        {
            if(Piece_Type_By_Square[sq] == pc)
            {
                And_Result = Bishop_Moves[sq] & All_Pieces;

                if(And_Result != 0)
                {
                    std::vector<unsigned int> TO_sqs;
                    std::vector<unsigned int> Blockers_sqs;
                    Get_SetBits_Indecies(Blockers_sqs,And_Result);

                    U64 Slider_Moves = FULL_BOARD;
                    for(unsigned i=0;i<Blockers_sqs.size();++i)
                    {
                        Slider_Moves = Get_Slider_Moves_Blocked_AtSq(pc,Piece_Type_By_Square[Blockers_sqs[i]],sq,squares(Blockers_sqs[i]),Slider_Moves);
                    }

                    Get_SetBits_Indecies(TO_sqs,Slider_Moves);

                    for(unsigned i=0;i<TO_sqs.size();++i)
                    {
                        Set_Move_Info((Moves->moves)+(Moves->Count),sq,TO_sqs[i],EMPTY,Piece_Type_By_Square[TO_sqs[i]],0,0,Game_Phase,false,Side_To_Move,false);
                        Moves->Count++;
                    }

                }
            }
        }
    }

    else if(pc == wR || pc == bR)
    {
        for(squares sq=a1;sq<OFF_BOARD;sq = squares(sq+b1))
        {
            if(Piece_Type_By_Square[sq] == pc)
            {
                And_Result = Rook_Moves[sq] & All_Pieces;

                if(And_Result != 0)
                {
                    std::vector<unsigned int> TO_sqs;
                    std::vector<unsigned int> Blockers_sqs;
                    Get_SetBits_Indecies(Blockers_sqs,And_Result);

                    U64 Slider_Moves = FULL_BOARD;
                    for(unsigned i=0;i<Blockers_sqs.size();++i)
                    {
                        Slider_Moves = Get_Slider_Moves_Blocked_AtSq(pc,Piece_Type_By_Square[Blockers_sqs[i]],sq,squares(Blockers_sqs[i]),Slider_Moves);
                    }

                    Get_SetBits_Indecies(TO_sqs,Slider_Moves);

                    for(unsigned i=0;i<TO_sqs.size();++i)
                    {
                        Set_Move_Info((Moves->moves)+(Moves->Count),sq,TO_sqs[i],EMPTY,Piece_Type_By_Square[TO_sqs[i]],0,0,Game_Phase,false,Side_To_Move,false);
                        Moves->Count++;
                    }

                }
            }
        }
    }

    else if(pc == wQ || pc == bQ)
    {
        for(squares sq=a1;sq<OFF_BOARD;sq = squares(sq+b1))
        {
            if(Piece_Type_By_Square[sq] == pc)
            {
                And_Result = Queen_Moves[sq] & All_Pieces;

                if(And_Result != 0)
                {
                    std::vector<unsigned int> TO_sqs;
                    std::vector<unsigned int> Blockers_sqs;
                    Get_SetBits_Indecies(Blockers_sqs,And_Result);

                    U64 Slider_Moves = FULL_BOARD;
                    for(unsigned i=0;i<Blockers_sqs.size();++i)
                    {
                        Slider_Moves = Get_Slider_Moves_Blocked_AtSq(pc,Piece_Type_By_Square[Blockers_sqs[i]],sq,squares(Blockers_sqs[i]),Slider_Moves);
                    }

                    Get_SetBits_Indecies(TO_sqs,Slider_Moves);

                    for(unsigned i=0;i<TO_sqs.size();++i)
                    {
                        Set_Move_Info((Moves->moves)+(Moves->Count),sq,TO_sqs[i],EMPTY,Piece_Type_By_Square[TO_sqs[i]],0,0,Game_Phase,false,Side_To_Move,false);
                        Moves->Count++;
                    }

                }
            }
        }
    }

    else if(pc == wK || pc == bK)
    {
        //Castling Moves
        if(pc == wK && KingSquare[0] == e1)
        {
            if(Castling_Permissions & CastleWhiteKside != 0 )
                if(Get_Piece_onSquare(f1) == EMPTY && Get_Piece_onSquare(g1) == EMPTY)
                     if(!Is_Square_Attacked(f1,BLACK) && !Is_Square_Attacked(g1,BLACK))
                     {
                         Set_Move_Info((Moves->moves)+(Moves->Count),e1,g1,EMPTY,EMPTY,CastleWhiteKside,0,MID_GAME,0,Side_To_Move,false);
                         Moves->Count++;
                         Set_Move_Info((Moves->moves)+(Moves->Count),h1,f1,EMPTY,EMPTY,0,0,MID_GAME,0,Side_To_Move,false);
                         Moves->Count++;
                     }

            if(Castling_Permissions & CastleWhiteQside != 0 )
                if(Get_Piece_onSquare(d1) == EMPTY && Get_Piece_onSquare(c1) == EMPTY && Get_Piece_onSquare(b1) == EMPTY)
                     if(!Is_Square_Attacked(d1,BLACK) && !Is_Square_Attacked(c1,BLACK))
                     {
                         Set_Move_Info((Moves->moves)+(Moves->Count),e1,c1,EMPTY,EMPTY,CastleWhiteQside,0,MID_GAME,0,Side_To_Move,false);
                         Moves->Count++;
                         Set_Move_Info((Moves->moves)+(Moves->Count),a1,d1,EMPTY,EMPTY,0,0,MID_GAME,0,Side_To_Move,false);
                         Moves->Count++;
                     }
        }

        else if(pc == bK && KingSquare[1] == e8)
        {
            if(Castling_Permissions & CastleBlackKside != 0 )
                if(Get_Piece_onSquare(f8) == EMPTY && Get_Piece_onSquare(g8) == EMPTY)
                     if(!Is_Square_Attacked(f8,WHITE) || !Is_Square_Attacked(g8,WHITE))
                     {
                         Set_Move_Info((Moves->moves)+(Moves->Count),e8,g8,EMPTY,EMPTY,CastleBlackKside,0,MID_GAME,0,Side_To_Move,false);
                         Moves->Count++;
                         Set_Move_Info((Moves->moves)+(Moves->Count),h8,f8,EMPTY,EMPTY,0,0,MID_GAME,0,Side_To_Move,false);
                         Moves->Count++;
                     }

            if(Castling_Permissions & CastleBlackQside != 0 )
                if(Get_Piece_onSquare(d8) == EMPTY && Get_Piece_onSquare(c8) == EMPTY && Get_Piece_onSquare(b8) == EMPTY)
                     if(!Is_Square_Attacked(d8,WHITE) || !Is_Square_Attacked(c8,WHITE))
                     {
                         Set_Move_Info((Moves->moves)+(Moves->Count),e8,c8,EMPTY,EMPTY,CastleBlackQside,0,MID_GAME,0,Side_To_Move,false);
                         Moves->Count++;
                         Set_Move_Info((Moves->moves)+(Moves->Count),a8,d8,EMPTY,EMPTY,0,0,MID_GAME,0,Side_To_Move,false);
                         Moves->Count++;
                     }
        }


            unsigned sq;

            if(pc == wK)
            {
                sq = KingSquare[WHITE];
                And_Result = (King_Moves[sq] | White_Pieces) ^ White_Pieces;
            }

            else
            {
                sq = KingSquare[BLACK];
                And_Result = (King_Moves[sq] | Black_Pieces) ^ Black_Pieces;
            }

             if(And_Result != 0)
                {
                    std::vector<unsigned int> TO_sqs;
                    Get_SetBits_Indecies(TO_sqs,And_Result);

                    for(unsigned i=0;i<TO_sqs.size();++i)
                    {
                        if(!Is_Square_Attacked(squares(TO_sqs[i]),pc==wK?BLACK:WHITE))
                        {
                            Set_Move_Info((Moves->moves)+(Moves->Count),sq,TO_sqs[i],EMPTY,Piece_Type_By_Square[TO_sqs[i]],0,0,Game_Phase,false,Side_To_Move,false);
                            Moves->Count++;
                        }
                    }

                }

    }
}
