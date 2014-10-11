#include "HashKey.h"

void Generate_HashKey(Board *board)
{
    U64 Key = 0;
    unsigned Enpassent;
    unsigned Castling_Permissions;
    pieces pc;

    /* Hashing board flags */

    if (board->Get_Side_To_Move() == BLACK)
        Key ^= BlackSideKey;

    Enpassent = board->Get_Enpassent();
    if (Enpassent < OFF_BOARD)
        Key ^= EnpassentFileKeys[GET_FILE_FROM_SQUARE(Enpassent)];

    Castling_Permissions = board->Get_Castling_Permissions();
    if (Castling_Permissions < UNKNOWN)
        Key ^= CastlingKeys[Castling_Permissions];

    /* Hashing pieces position */

    for(squares i=a1; i<OFF_BOARD ; i = squares(i+1))
    {
       pc = board->Get_Piece_onSquare(i);
       if(pc != EMPTY)
          Key ^= PieceKeys[pc][i];
    }

    board->Set_HashKey(Key);
}
