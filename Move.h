#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include "Board.h"


#define FROM_FLAG 0x3f                  //0000 0000 0000 0000 0000 0000 0011 1111
#define TO_FLAG 0xfc0                   //0000 0000 0000 0000 0000 1111 1100 0000
#define PROMOTION_FLAG 0x3f000          //0000 0000 0000 0011 1111 0000 0000 0000
#define CAPTURED_FLAG 0x3c0000          //0000 0000 0011 1100 0000 0000 0000 0000
#define CASTLING_FLAG 0x3c00000         //0000 0011 1100 0000 0000 0000 0000 0000
#define REPETITION_FLAG 0xc000000       //0000 1100 0000 0000 0000 0000 0000 0000
#define PHASE_FLAG 0x30000000           //0011 0000 0000 0000 0000 0000 0000 0000
#define ENPASSENT_FLAG 0x40000000       //0100 0000 0000 0000 0000 0000 0000 0000
#define SIDE_FLAG 0x80000000            //1000 0000 0000 0000 0000 0000 0000 0000


#define GET_FROM_SQUARE(n) ( (n) & FROM_FLAG )
#define SET_FROM_SQUARE(n,sq)  ( ( (n) & (~FROM_FLAG) ) | (sq) )

#define GET_TO_SQUARE(n) ( ( (n) & TO_FLAG ) >> 6)
#define SET_TO_SQUARE(n,sq) ( ( (n) & (~TO_FLAG) ) | ( (sq) << 6 ) )

#define GET_PROMOTED_PIECE(n) ( ( (n) & PROMOTION_FLAG ) >> 12 )
#define SET_PROMOTED_PIECE(n,sq) ( ( (n) & (~PROMOTION_FLAG) ) | ( (sq) << 12 ) )

#define GET_CAPTURED_PIECE(n) ( ( (n) & CAPTURED_FLAG ) >> 18 )
#define SET_CAPTURED_PIECE(n,pc) ( ( (n) & (~CAPTURED_FLAG) ) | ( (pc) << 18 ) )

#define GET_CASTLING_PERMISSIONS(n) ( ( (n) & CASTLING_FLAG ) >> 22 )
#define SET_CASTLING_PERMISSIONS(n,cp) ( ( (n) & (~CASTLING_FLAG) ) | ( (cp) << 22 ) )

#define GET_REPETITION_FROM_MOVE(n) ( ( (n) & REPETITION_FLAG ) >> 26 )
#define SET_REPETITION_FLAG(n,x) ( ( (n) & (~REPETITION_FLAG) ) | ( (x) << 26 ) )

#define GET_GAME_PHASE(n) ( ( (n) & PHASE_FLAG ) >> 28 )
#define SET_GAME_PHASE(n,p) ( ( (n) & (~PHASE_FLAG) ) | ( (p) << 28 ) )

#define IS_ENPASSENT(n) ( ( (n) & ENPASSENT_FLAG ) >> 30 )
#define SET_ENPASSENT(n) ( (n) | ( 1 << 30 ) )

#define GET_SIDE_TO_PLAY(n) ( ( (n) & SIDE_FLAG ) >> 31 )
#define SET_SIDE_TO_PLAY(n) ( (n) | ( 1 << 31 ) )


inline void Add_Quiet_Move(const Board *board,unsigned info,Possible_Moves *Moves_List)
{
    Moves_List->moves[Moves_List->Count].Info = info;
    Moves_List->moves[Moves_List->Count].Score = 0;
    Moves_List->Count++;
}

inline void Add_Capture_Move(const Board *board,unsigned info,Possible_Moves *Moves_List)
{
    Moves_List->moves[Moves_List->Count].Info = info;
    Moves_List->moves[Moves_List->Count].Score = 0;
    Moves_List->Count++;
}

inline void Add_EnPassent_Move(const Board *board,unsigned info,Possible_Moves *Moves_List)
{
    Moves_List->moves[Moves_List->Count].Info = info;
    Moves_List->moves[Moves_List->Count].Score = 0;
    Moves_List->Count++;
}

inline void Add_Castling_Move(const Board *board,unsigned info,Possible_Moves *Moves_List)
{
    Moves_List->moves[Moves_List->Count].Info = info;
    Moves_List->moves[Moves_List->Count].Score = 0;
    Moves_List->Count++;
}

inline void Generate_All_Moves(const Board *board,Possible_Moves *Moves_List)
{
    Moves_List->Count = 0;
    pieces Lower_Limit , Upper_Limit;

    if(board->Get_Side_To_Move() == WHITE)
    {
      Lower_Limit = wP;
      Upper_Limit = bK;
    }

    else if(board->Get_Side_To_Move() == BLACK)
    {
      Lower_Limit = bP;
      Upper_Limit = EMPTY;
    }

    else //Both sides
    {
      Lower_Limit = wP;
      Upper_Limit = EMPTY;
    }

    for(pieces pc=Lower_Limit;pc<Upper_Limit;pc = pieces(pc+1))
    {
        if(board->Get_Piece_Count(pc) != 0)
            board->Get_Possible_Moves_By_Piece_Type(Moves_List,pc);
    }

}

#endif // MOVE_H_INCLUDED
