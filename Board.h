#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "Definitions.h"
#include <vector>

class Board
{
public:
     Board();


     /* Board Methods */

     bool Init_Board();
     void Display_Board();

     bool Set_Piece_onSquare(pieces ,squares);
     pieces Get_Piece_onSquare(squares) const;
     bool Clear_Square(squares);

     unsigned Get_Piece_Count(pieces) const;

     bool Set_Side_To_Move(side);
     side Get_Side_To_Move() const;

     void Set_Enpassent(squares);
     squares Get_Enpassent() const;

     bool Set_Full_Moves_Count(unsigned);
     void Inc_Full_Moves_Count();
     unsigned Get_Full_Moves_Count() const;

     bool Set_Castling_Permissions(unsigned);
     unsigned Get_Castling_Permissions() const;

     bool Set_Fify_Move_Count(unsigned);
     void Inc_Fifty_Move_Count();
     unsigned Get_Fify_Move_Count() const;
     void Reset_Fify_Move_Count();

     void Set_HashKey(U64);
     U64 Get_HashKey() const;

     void Inc_Repetition_Count();
     void Reset_Reptition_Count();
     unsigned Get_Repetition_Count() const;

     void Set_Board_FEN(char* ,unsigned Length);
     char* Get_Board_FEN() const;

     bool Set_Game_Phase(phase);
     phase Get_Game_Phase() const;

     void Add_Move_To_History(Move);
     Move Get_Last_Move() const;
     void Pop_Last_Move();

     bool Is_Square_Attacked(squares,side) const;
     bool Is_Square_Attacked_By_Piece(squares,pieces) const;

     void Get_Possible_Moves_By_Piece_Type(Possible_Moves*,pieces) const;


protected:
     bool Init_Board_Pieces();
     bool Init_Board_Flags();

private:

    /* Board Pieces */

     U64 White_Pawns;
     U64 White_Knights;
     U64 White_Bishops;
     U64 White_Rooks;
     U64 White_Queens;
     U64 White_King;
     U64 White_Pieces;

     U64 Black_Pawns;
     U64 Black_Knights;
     U64 Black_Bishops;
     U64 Black_Rooks;
     U64 Black_Queens;
     U64 Black_King;
     U64 Black_Pieces;

     U64 All_Pieces;
     pieces Piece_Type_By_Square[64];



    /* Board Flags */

    side Side_To_Move;
    squares Enpassent;
    squares KingSquare[2];
    unsigned Full_Moves_Count;
    unsigned Fify_Move_Count;

    /********************************************************************************/
    /* Castling Permissions either:                                                 */
    /* 16 for "UNKOWN"                                0001 0000                     */
    /* 1 for "white castle king side"                 0000 0001                     */
    /* 2 for "white castle queen side"                0000 0010                     */
    /* 4 for "black castle king side"                 0000 0100                     */
    /* 8 for "black castle queen side"                0000 1000                     */
    /* or any combinations of those.                                                */
    /* so can't exceed 1+2+4+8 = 15 in any case.      0000 1111                     */
    /********************************************************************************/

    unsigned Castling_Permissions;

    phase Game_Phase;
    U64 HashKey;
    unsigned Repetition_Count;

    std::vector<Move> History;

    char* Board_FEN;

};

#endif // BOARD_H_INCLUDED
