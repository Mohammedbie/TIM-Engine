#include "PERFT.h"
#include "Move.h"

U64 Perft(Board *board,unsigned depth)
{
    U64 Nodes_Count = 0;
    Possible_Moves *moves = new Possible_Moves;
    Generate_All_Moves(board,moves);

    if(depth == 0) return 1;

    for(unsigned i=0;i<moves->Count;++i)
    {
        Make_Move(board,(moves->moves)+i);
        Nodes_Count += Perft(board,depth-1);
        UNDO_Move(board);
    }

    delete moves;

    return Nodes_Count;
}
