/*

*/

#include "FEN.h"
#include <iostream>
#include <map>
#include <algorithm>
#include "HashKey.h"

FENparser::FENparser(char* FEN,Board *b)
{
    b->Init_Board();

    unsigned index = 0,sq = 0;
    squares square;

    while(FEN[index] != ' ')
    {
        square = Squares_Notation64[sq];

        if(FEN[index] == 'r')
            b->Set_Piece_onSquare(bR,square);
        else if(FEN[index] == 'n')
            b->Set_Piece_onSquare(bN,square);
        else if(FEN[index] == 'b')
            b->Set_Piece_onSquare(bB,square);
        else if(FEN[index] == 'q')
            b->Set_Piece_onSquare(bQ,square);
        else if(FEN[index] == 'k')
            b->Set_Piece_onSquare(bK,square);
        else if(FEN[index] == 'p')
            b->Set_Piece_onSquare(bP,square);

        else if(FEN[index] == 'R')
            b->Set_Piece_onSquare(wR,square);
        else if(FEN[index] == 'N')
            b->Set_Piece_onSquare(wN,square);
        else if(FEN[index] == 'B')
            b->Set_Piece_onSquare(wB,square);
        else if(FEN[index] == 'Q')
            b->Set_Piece_onSquare(wQ,square);
        else if(FEN[index] == 'K')
            b->Set_Piece_onSquare(wK,square);
        else if(FEN[index] == 'P')
            b->Set_Piece_onSquare(wP,square);

        else if(FEN[index] == '8')
            sq += 7;
        else if(FEN[index] == '7')
            sq += 6;
        else if(FEN[index] == '6')
            sq += 5;
        else if(FEN[index] == '5')
            sq += 4;
        else if(FEN[index] == '4')
            sq += 3;
        else if(FEN[index] == '3')
            sq += 2;
        else if(FEN[index] == '2')
            sq += 1;


        if(FEN[index] != '/')
            sq++;

        index++;
    }

    if(FEN[++index] == 'w')
        b->Set_Side_To_Move(WHITE);
    else if(FEN[index] == 'b')
        b->Set_Side_To_Move(BLACK);
    else
        std::cout << "Error parsing FEN.\n";

    index += 2;

    Castling_Permissions = 0;

    char* pt;

    pt = std::find(FEN+index,FEN+index+4,'K');
    if(pt != FEN+index+4)
        Castling_Permissions += CastleWhiteKside;

    pt = std::find(FEN+index,FEN+index+4,'Q');
    if(pt != FEN+index+4)
        Castling_Permissions += CastleWhiteQside;

     pt = std::find(FEN+index,FEN+index+4,'k');
    if(pt != FEN+index+4)
        Castling_Permissions += CastleBlackKside;

     pt = std::find(FEN+index,FEN+index+4,'q');
    if(pt != FEN+index+4)
        Castling_Permissions += CastleBlackQside;

    while(FEN[index] != ' ')
    {
        index++;
    }

    if(FEN[++index] == '-')
        Enpassent = OFF_BOARD;
    else
        Enpassent = GET_SQUARE_FROM_FILE_AND_RANK_STRING(FEN[index],FEN[++index]);

    index += 2;
    Fifty_Move_Counter = FEN[index] - '0';

    index += 2;
    Full_Moves_Count = FEN[index] - '0';

    if(Castling_Permissions)
       b->Set_Castling_Permissions(Castling_Permissions);

    b->Set_Enpassent(Enpassent);
    b->Set_Full_Moves_Count(Full_Moves_Count);
    b->Set_Fify_Move_Count(Fifty_Move_Counter);
    b->Set_Board_FEN(FEN,index+1);

    Generate_HashKey(b);

    b->Display_Board();
}
