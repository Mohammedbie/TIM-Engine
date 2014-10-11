#ifndef FEN_H_INCLUDED
#define FEN_H_INCLUDED

#include "Board.h"

class FENparser
{
public:
    FENparser(char* FEN, Board*);

private:
    unsigned Full_Moves_Count;
    unsigned Fifty_Move_Counter;
    squares Enpassent;
    unsigned Castling_Permissions;

};

#endif // FEN_H_INCLUDED
