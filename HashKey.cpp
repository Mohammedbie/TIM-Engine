#include "HashKey.h"


void Generate_HashKey(Board *board)
{
    U64 Key = 0;
    unsigned Enpassent;
    unsigned Castling_Permissions;
    pieces pc;

    /* Hashing board flags */

    if (board->Get_Side_To_Move() == BLACK)
       Key = Add_Key_To_HashKey(BlackSideKey,Key);

    Enpassent = board->Get_Enpassent();
    if (Enpassent < OFF_BOARD)
        Key = Add_Key_To_HashKey(EnpassentFileKeys[GET_FILE_FROM_SQUARE(Enpassent)],Key);

    Castling_Permissions = board->Get_Castling_Permissions();
    if (Castling_Permissions < UNKNOWN)
        Key = Add_Key_To_HashKey(CastlingKeys[Castling_Permissions],Key);

    /* Hashing pieces position */

    for(squares i=a1; i<OFF_BOARD ; i = squares(i+1))
    {
       pc = board->Get_Piece_onSquare(i);
       if(pc != EMPTY)
         Key = Add_Key_To_HashKey(PieceKeys[pc][i],Key);
    }


    board->Set_HashKey(Key);
}
