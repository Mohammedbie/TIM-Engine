#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED

#define _GCC_

#include <vector>
#include "iostream"
//#include <fstream>

//static std::ofstream out("board.txt");

#define FULL_BOARD 0xffffffffffffffff

#define INVAILD 1000
#define SQUARES_PER_SIDE 8
#define AVERAGE_GAME_MOVES 120
#define MAX_POSSIBLE_MOVES_SIZE 256


#define MAX_POSSIBLE_PAWN_MOVES 4
#define MAX_POSSIBLE_KNIGHT_MOVES 8
#define MAX_POSSIBLE_BISHOP_MOVES 13
#define MAX_POSSIBLE_ROOK_MOVES 14
#define MAX_POSSIBLE_QUEEN_MOVES 27
#define MAX_POSSIBLE_KING_MOVES 8

#define ABS(n) ( (n) > 0 ? (n) : -(n))

#define GET_PIECE_COLOUR(pc) ( (pc) / 6 ) //0 = WHITE , 1 = BLACK , 2 = ANY

#define POSITIVE45_DIAGONAL 45
#define NEGATIVE45_DIAGONAL -45
#define HORIZONTAL -180
#define VERTICAL 90

#define GET_DIAGONAL(x,y) ( ABS( int(x) - int(y) ) % 9 == 0 ? POSITIVE45_DIAGONAL : NEGATIVE45_DIAGONAL )
#define GET_AXIS(x,y) ( ABS( int(x) - int(y) ) % 8 == 0 ? VERTICAL : HORIZONTAL )

#define ON_VERTICAL_LINE(x,y) (GET_AXIS(x,y) == VERTICAL ? true : false)
#define ON_HORIZONTAL_LINE(x,y) ( ((ABS( int(x) - int(y) ) < 8 ) && (ABS( int(x) - int(y) ) % 7 != 0)) ? true : false )

#define F (FROM)
#define PP (Promoted_Piece)
#define CAP (Captured_pc)
#define CP (Castling_Permisson)
#define RP (Repitition)
#define GP (Game_Phase)
#define EP (EnPassent)
#define IBT (Is_Black_turn)
#define IPS (Is_Pawn_Start)

#define GET_FILE_FROM_SQUARE(n) ((n) % 8 )
#define GET_RANK_FROM_SQUARE(n) ((n) / 8 )
#define GET_SQUARE_FROM_FILE_AND_RANK_STRING(x,y) (static_cast<squares>(int((x) - 'a') + SQUARES_PER_SIDE * int((y) - '1')) )
#define GET_SQUARE_FROM_FILE_AND_RANK(x,y) ( (x) + SQUARES_PER_SIDE * ((y)+1) )

#define SET_SQUARE(n) ((U64(1)) << (n))

#define GET_ENPASSENT_SQUARE(side,square) ( (side) == WHITE ? squares(square-8):squares(square+8) )



typedef unsigned long long U64;

/* Board */
static const char* Bools[2] = {"No","Yes"};

enum side {WHITE,BLACK,ANY};
static const char* Colour[3] = {"White","Black","Any"};

enum files {A_File,B_File,C_File,D_File,E_File,F_File,G_File,H_File};
enum ranks {Rank_1,Rank_2,Rank_3,Rank_4,Rank_5,Rank_6,Rank_7,Rank_8};

enum squares {a1,b1,c1,d1,e1,f1,g1,h1,
              a2,b2,c2,d2,e2,f2,g2,h2,
              a3,b3,c3,d3,e3,f3,g3,h3,
              a4,b4,c4,d4,e4,f4,g4,h4,
              a5,b5,c5,d5,e5,f5,g5,h5,
              a6,b6,c6,d6,e6,f6,g6,h6,
              a7,b7,c7,d7,e7,f7,g7,h7,
              a8,b8,c8,d8,e8,f8,g8,h8,OFF_BOARD};

static const char* Squares_Name[65] = {"a1","b1","c1","d1","e1","f1","g1","h1",
                                       "a2","b2","c2","d2","e2","f2","g2","h2",
                                       "a3","b3","c3","d3","e3","f3","g3","h3",
                                       "a4","b4","c4","d4","e4","f4","g4","h4",
                                       "a5","b5","c5","d5","e5","f5","g5","h5",
                                       "a6","b6","c6","d6","e6","f6","g6","h6",
                                       "a7","b7","c7","d7","e7","f7","g7","h7",
                                       "a8","b8","c8","d8","e8","f8","g8","h8","-"};

static const squares Squares_Notation64[64] = {a8,b8,c8,d8,e8,f8,g8,h8,
                                               a7,b7,c7,d7,e7,f7,g7,h7,
                                               a6,b6,c6,d6,e6,f6,g6,h6,
                                               a5,b5,c5,d5,e5,f5,g5,h5,
                                               a4,b4,c4,d4,e4,f4,g4,h4,
                                               a3,b3,c3,d3,e3,f3,g3,h3,
                                               a2,b2,c2,d2,e2,f2,g2,h2,
                                               a1,b1,c1,d1,e1,f1,g1,h1};

enum pieces {wP,wN,wB,wR,wQ,wK,bP,bN,bB,bR,bQ,bK,EMPTY,ALL}; //wP stands for white Pawn and so on

static const char* Pieces_Name[] = {"WhitePawn","WhiteKnight","WhiteBishop","WhiteRook","WhiteQueen","WhiteKing","BlackPawn","BlackKnight","BlackBishop","BlackRook","BlackQueen","BlackKing","EMPTY","All_Pieces"};

enum castling {CastleWhiteKside = 1 ,CastleWhiteQside = 2 ,CastleBlackKside = 4 ,CastleBlackQside = 8 ,UNKNOWN = 16};

enum phase {OPEN_GAME,MID_GAME,END_GAME,NONE};



/* Precomputed Attack/Move tables */

//Starting from White Pawn at a1 attacks
const U64 White_Pawn_Direct_Attacks[64] = {0x200 , 0x500 , 0xa00 , 0x1400 , 0x2800 , 0x5000 , 0xa000 , 0x4000 , 0x20000 ,
                                           0x50000 , 0xa0000 , 0x140000 , 0x280000 , 0x500000 , 0xa00000 , 0x400000 , 0x2000000 ,
                                           0x5000000 , 0xa000000 , 0x14000000 , 0x28000000 , 0x50000000 , 0xa0000000 , 0x40000000 , 0x200000000 ,
                                           0x500000000 , 0xa00000000 , 0x1400000000 , 0x2800000000 , 0x5000000000 , 0xa000000000 , 0x4000000000 , 0x20000000000 ,
                                           0x50000000000 , 0xa0000000000 , 0x140000000000 , 0x280000000000 , 0x500000000000 , 0xa00000000000 , 0x400000000000 , 0x2000000000000 ,
                                           0x5000000000000 , 0xa000000000000 , 0x14000000000000 , 0x28000000000000 , 0x50000000000000 , 0xa0000000000000 , 0x40000000000000 , 0x200000000000000 ,
                                           0x500000000000000 , 0xa00000000000000 , 0x1400000000000000 , 0x2800000000000000 , 0x5000000000000000 , 0xa000000000000000 , 0x4000000000000000 , 0x0 ,
                                           0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 };

//Starting from Black Pawn at a1 attacks
const U64 Black_Pawn_Direct_Attacks[64] = {0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x2 ,
                                           0x5 , 0xa , 0x14 , 0x28 , 0x50 , 0xa0 , 0x40 , 0x200 ,
                                           0x500 , 0xa00 , 0x1400 , 0x2800 , 0x5000 , 0xa000 , 0x4000 , 0x20000 ,
                                           0x50000 , 0xa0000 , 0x140000 , 0x280000 , 0x500000 , 0xa00000 , 0x400000 , 0x2000000 ,
                                           0x5000000 , 0xa000000 , 0x14000000 , 0x28000000 , 0x50000000 , 0xa0000000 , 0x40000000 , 0x200000000 ,
                                           0x500000000 , 0xa00000000 , 0x1400000000 , 0x2800000000 , 0x5000000000 , 0xa000000000 , 0x4000000000 , 0x20000000000 ,
                                           0x50000000000 , 0xa0000000000 , 0x140000000000 , 0x280000000000 , 0x500000000000 , 0xa00000000000 , 0x400000000000 , 0x2000000000000 ,
                                           0x5000000000000 , 0xa000000000000 , 0x14000000000000 , 0x28000000000000 , 0x50000000000000 , 0xa0000000000000 , 0x40000000000000 };

//Starting from Knight at a1 moves
const U64 Knight_Moves[64] = {0x20400 , 0x50800 , 0xa1100 , 0x142200 , 0x284400 , 0x508800 , 0xa01000 , 0x402000 , 0x2040004 ,
                              0x5080008 , 0xa110011 , 0x14220022 , 0x28440044 , 0x50880088 , 0xa0100010 , 0x40200020 , 0x204000402 ,
                              0x508000805 , 0xa1100110a , 0x1422002214 , 0x2844004428 , 0x5088008850 , 0xa0100010a0 , 0x4020002040 , 0x20400040200 ,
                              0x50800080500 , 0xa1100110a00 , 0x142200221400 , 0x284400442800 , 0x508800885000 , 0xa0100010a000 , 0x402000204000 , 0x2040004020000 ,
                              0x5080008050000 , 0xa1100110a0000 , 0x14220022140000 , 0x28440044280000 , 0x50880088500000 , 0xa0100010a00000 , 0x40200020400000 , 0x204000402000000 ,
                              0x508000805000000 , 0xa1100110a000000 , 0x1422002214000000 , 0x2844004428000000 , 0x5088008850000000 , 0xa0100010a0000000 , 0x4020002040000000 , 0x400040200000000 ,
                              0x800080500000000 , 0x1100110a00000000 , 0x2200221400000000 , 0x4400442800000000 , 0x8800885000000000 , 0x100010a000000000 , 0x2000204000000000 , 0x4020000000000 ,
                              0x8050000000000 , 0x110a0000000000 , 0x22140000000000 , 0x44280000000000 , 0x88500000000000 , 0x10a00000000000 , 0x20400000000000 };

//Starting from Bishop at a1 moves
const U64 Bishop_Moves[64] = {0x8040201008040200 , 0x80402010080500 , 0x804020110a00 , 0x8041221400 , 0x182442800 , 0x10204885000 , 0x102040810a000 , 0x102040810204000 , 0x4020100804020002 ,
                              0x8040201008050005 , 0x804020110a000a , 0x804122140014 , 0x18244280028 , 0x1020488500050 , 0x102040810a000a0 , 0x204081020400040 , 0x2010080402000204 ,
                              0x4020100805000508 , 0x804020110a000a11 , 0x80412214001422 , 0x1824428002844 , 0x102048850005088 , 0x2040810a000a010 , 0x408102040004020 , 0x1008040200020408 ,
                              0x2010080500050810 , 0x4020110a000a1120 , 0x8041221400142241 , 0x182442800284482 , 0x204885000508804 , 0x40810a000a01008 , 0x810204000402010 , 0x804020002040810 ,
                              0x1008050005081020 , 0x20110a000a112040 , 0x4122140014224180 , 0x8244280028448201 , 0x488500050880402 , 0x810a000a0100804 , 0x1020400040201008 , 0x402000204081020 ,
                              0x805000508102040 , 0x110a000a11204080 , 0x2214001422418000 , 0x4428002844820100 , 0x8850005088040201 , 0x10a000a010080402 , 0x2040004020100804 , 0x200020408102040 ,
                              0x500050810204080 , 0xa000a1120408000 , 0x1400142241800000 , 0x2800284482010000 , 0x5000508804020100 , 0xa000a01008040201 , 0x4000402010080402 , 0x2040810204080 ,
                              0x5081020408000 , 0xa112040800000 , 0x14224180000000 , 0x28448201000000 , 0x50880402010000 , 0xa0100804020100 , 0x40201008040201 };

//Starting from Rook at a1 moves
const U64 Rook_Moves[64] = {0x1010101010101fe , 0x2020202020202fd , 0x4040404040404fb , 0x8080808080808f7 , 0x10101010101010ef , 0x20202020202020df , 0x40404040404040bf , 0x808080808080807f , 0x10101010101fe01 ,
                            0x20202020202fd02 , 0x40404040404fb04 , 0x80808080808f708 , 0x101010101010ef10 , 0x202020202020df20 , 0x404040404040bf40 , 0x8080808080807f80 , 0x101010101fe0101 ,
                            0x202020202fd0202 , 0x404040404fb0404 , 0x808080808f70808 , 0x1010101010ef1010 , 0x2020202020df2020 , 0x4040404040bf4040 , 0x80808080807f8080 , 0x1010101fe010101 ,
                            0x2020202fd020202 , 0x4040404fb040404 , 0x8080808f7080808 , 0x10101010ef101010 , 0x20202020df202020 , 0x40404040bf404040 , 0x808080807f808080 , 0x10101fe01010101 ,
                            0x20202fd02020202 , 0x40404fb04040404 , 0x80808f708080808 , 0x101010ef10101010 , 0x202020df20202020 , 0x404040bf40404040 , 0x8080807f80808080 , 0x101fe0101010101 ,
                            0x202fd0202020202 , 0x404fb0404040404 , 0x808f70808080808 , 0x1010ef1010101010 , 0x2020df2020202020 , 0x4040bf4040404040 , 0x80807f8080808080 , 0x1fe010101010101 ,
                            0x2fd020202020202 , 0x4fb040404040404 , 0x8f7080808080808 , 0x10ef101010101010 , 0x20df202020202020 , 0x40bf404040404040 , 0x807f808080808080 , 0xfe01010101010101 ,
                            0xfd02020202020202 , 0xfb04040404040404 , 0xf708080808080808 , 0xef10101010101010 , 0xdf20202020202020 , 0xbf40404040404040 , 0x7f80808080808080 };

//Starting from Queen at a1 moves
const U64 Queen_Moves[64] = {0x81412111090503fe , 0x2824222120a07fd , 0x404844424150efb , 0x8080888492a1cf7 , 0x10101011925438ef , 0x2020212224a870df , 0x404142444850e0bf , 0x8182848890a0c07f , 0x412111090503fe03 ,
                             0x824222120a07fd07 , 0x4844424150efb0e , 0x80888492a1cf71c , 0x101011925438ef38 , 0x20212224a870df70 , 0x4142444850e0bfe0 , 0x82848890a0c07fc0 , 0x2111090503fe0305 ,
                             0x4222120a07fd070a , 0x844424150efb0e15 , 0x888492a1cf71c2a , 0x1011925438ef3854 , 0x212224a870df70a8 , 0x42444850e0bfe050 , 0x848890a0c07fc0a0 , 0x11090503fe030509 ,
                             0x22120a07fd070a12 , 0x4424150efb0e1524 , 0x88492a1cf71c2a49 , 0x11925438ef385492 , 0x2224a870df70a824 , 0x444850e0bfe05048 , 0x8890a0c07fc0a090 , 0x90503fe03050911 ,
                             0x120a07fd070a1222 , 0x24150efb0e152444 , 0x492a1cf71c2a4988 , 0x925438ef38549211 , 0x24a870df70a82422 , 0x4850e0bfe0504844 , 0x90a0c07fc0a09088 , 0x503fe0305091121 ,
                             0xa07fd070a122242 , 0x150efb0e15244484 , 0x2a1cf71c2a498808 , 0x5438ef3854921110 , 0xa870df70a8242221 , 0x50e0bfe050484442 , 0xa0c07fc0a0908884 , 0x3fe030509112141 ,
                             0x7fd070a12224282 , 0xefb0e1524448404 , 0x1cf71c2a49880808 , 0x38ef385492111010 , 0x70df70a824222120 , 0xe0bfe05048444241 , 0xc07fc0a090888482 , 0xfe03050911214181 ,
                             0xfd070a1222428202 , 0xfb0e152444840404 , 0xf71c2a4988080808 , 0xef38549211101010 , 0xdf70a82422212020 , 0xbfe0504844424140 , 0x7fc0a09088848281 };

//Starting from King at a1 moves , not including castling moves
const U64 King_Moves[64] = {0x302 , 0x705 , 0xe0a , 0x1c14 , 0x3828 , 0x7050 , 0xe0a0 , 0xc040 , 0x30203 ,
                            0x70507 , 0xe0a0e , 0x1c141c , 0x382838 , 0x705070 , 0xe0a0e0 , 0xc040c0 , 0x3020300 ,
                            0x7050700 , 0xe0a0e00 , 0x1c141c00 , 0x38283800 , 0x70507000 , 0xe0a0e000 , 0xc040c000 , 0x302030000 ,
                            0x705070000 , 0xe0a0e0000 , 0x1c141c0000 , 0x3828380000 , 0x7050700000 , 0xe0a0e00000 , 0xc040c00000 , 0x30203000000 ,
                            0x70507000000 , 0xe0a0e000000 , 0x1c141c000000 , 0x382838000000 , 0x705070000000 , 0xe0a0e0000000 , 0xc040c0000000 , 0x3020300000000 ,
                            0x7050700000000 , 0xe0a0e00000000 , 0x1c141c00000000 , 0x38283800000000 , 0x70507000000000 , 0xe0a0e000000000 , 0xc040c000000000 , 0x302030000000000 ,
                            0x705070000000000 , 0xe0a0e0000000000 , 0x1c141c0000000000 , 0x3828380000000000 , 0x7050700000000000 , 0xe0a0e00000000000 , 0xc040c00000000000 , 0x203000000000000 ,
                            0x507000000000000 , 0xa0e000000000000 , 0x141c000000000000 , 0x2838000000000000 , 0x5070000000000000 , 0xa0e0000000000000 , 0x40c0000000000000 };

/* Line Masks */
const U64 Vertical_Line_Mask[64] = { 0x101010101010100 , 0x202020202020200 , 0x404040404040400 , 0x808080808080800 , 0x1010101010101000 , 0x2020202020202000 , 0x4040404040404000 , 0x8080808080808000 , 0x101010101010001 ,
                                     0x202020202020002 , 0x404040404040004 , 0x808080808080008 , 0x1010101010100010 , 0x2020202020200020 , 0x4040404040400040 , 0x8080808080800080 , 0x101010101000101 ,
                                     0x202020202000202 , 0x404040404000404 , 0x808080808000808 , 0x1010101010001010 , 0x2020202020002020 , 0x4040404040004040 , 0x8080808080008080 , 0x101010100010101 ,
                                     0x202020200020202 , 0x404040400040404 , 0x808080800080808 , 0x1010101000101010 , 0x2020202000202020 , 0x4040404000404040 , 0x8080808000808080 , 0x101010001010101 ,
                                     0x202020002020202 , 0x404040004040404 , 0x808080008080808 , 0x1010100010101010 , 0x2020200020202020 , 0x4040400040404040 , 0x8080800080808080 , 0x101000101010101 ,
                                     0x202000202020202 , 0x404000404040404 , 0x808000808080808 , 0x1010001010101010 , 0x2020002020202020 , 0x4040004040404040 , 0x8080008080808080 , 0x100010101010101 ,
                                     0x200020202020202 , 0x400040404040404 , 0x800080808080808 , 0x1000101010101010 , 0x2000202020202020 , 0x4000404040404040 , 0x8000808080808080 , 0x1010101010101 ,
                                     0x2020202020202 , 0x4040404040404 , 0x8080808080808 , 0x10101010101010 , 0x20202020202020 , 0x40404040404040 , 0x80808080808080 };

const U64 Horizontal_Line_Mask[64] = { 0xfe , 0xfd , 0xfb , 0xf7 , 0xef , 0xdf , 0xbf , 0x7f , 0xfe00 ,
                                       0xfd00 , 0xfb00 , 0xf700 , 0xef00 , 0xdf00 , 0xbf00 , 0x7f00 , 0xfe0000 ,
                                       0xfd0000 , 0xfb0000 , 0xf70000 , 0xef0000 , 0xdf0000 , 0xbf0000 , 0x7f0000 , 0xfe000000 ,
                                       0xfd000000 , 0xfb000000 , 0xf7000000 , 0xef000000 , 0xdf000000 , 0xbf000000 , 0x7f000000 , 0xfe00000000 ,
                                       0xfd00000000 , 0xfb00000000 , 0xf700000000 , 0xef00000000 , 0xdf00000000 , 0xbf00000000 , 0x7f00000000 , 0xfe0000000000 ,
                                       0xfd0000000000 , 0xfb0000000000 , 0xf70000000000 , 0xef0000000000 , 0xdf0000000000 , 0xbf0000000000 , 0x7f0000000000 , 0xfe000000000000 ,
                                       0xfd000000000000 , 0xfb000000000000 , 0xf7000000000000 , 0xef000000000000 , 0xdf000000000000 , 0xbf000000000000 , 0x7f000000000000 , 0xfe00000000000000 ,
                                       0xfd00000000000000 , 0xfb00000000000000 , 0xf700000000000000 , 0xef00000000000000 , 0xdf00000000000000 , 0xbf00000000000000 , 0x7f00000000000000 };

const U64 Positive45_Line_Mask[64] = { 0x8040201008040200 , 0x80402010080400 , 0x804020100800 , 0x8040201000 , 0x80402000 , 0x804000 , 0x8000 , 0x0 , 0x4020100804020000 ,
                                       0x8040201008040001 , 0x80402010080002 , 0x804020100004 , 0x8040200008 , 0x80400010 , 0x800020 , 0x40 , 0x2010080402000000 ,
                                       0x4020100804000100 , 0x8040201008000201 , 0x80402010000402 , 0x804020000804 , 0x8040001008 , 0x80002010 , 0x4020 , 0x1008040200000000 ,
                                       0x2010080400010000 , 0x4020100800020100 , 0x8040201000040201 , 0x80402000080402 , 0x804000100804 , 0x8000201008 , 0x402010 , 0x804020000000000 ,
                                       0x1008040001000000 , 0x2010080002010000 , 0x4020100004020100 , 0x8040200008040201 , 0x80400010080402 , 0x800020100804 , 0x40201008 , 0x402000000000000 ,
                                       0x804000100000000 , 0x1008000201000000 , 0x2010000402010000 , 0x4020000804020100 , 0x8040001008040201 , 0x80002010080402 , 0x4020100804 , 0x200000000000000 ,
                                       0x400010000000000 , 0x800020100000000 , 0x1000040201000000 , 0x2000080402010000 , 0x4000100804020100 , 0x8000201008040201 , 0x402010080402 , 0x0 ,
                                       0x1000000000000 , 0x2010000000000 , 0x4020100000000 , 0x8040201000000 , 0x10080402010000 , 0x20100804020100 , 0x40201008040201 };

const U64 Negative45_Line_Mask[64] = { 0x0 , 0x100 , 0x10200 , 0x1020400 , 0x102040800 , 0x10204081000 , 0x1020408102000 , 0x102040810204000 , 0x2 ,
                                       0x10004 , 0x1020008 , 0x102040010 , 0x10204080020 , 0x1020408100040 , 0x102040810200080 , 0x204081020400000 , 0x204 ,
                                       0x1000408 , 0x102000810 , 0x10204001020 , 0x1020408002040 , 0x102040810004080 , 0x204081020008000 , 0x408102040000000 , 0x20408 ,
                                       0x100040810 , 0x10200081020 , 0x1020400102040 , 0x102040800204080 , 0x204081000408000 , 0x408102000800000 , 0x810204000000000 , 0x2040810 ,
                                       0x10004081020 , 0x1020008102040 , 0x102040010204080 , 0x204080020408000 , 0x408100040800000 , 0x810200080000000 , 0x1020400000000000 , 0x204081020 ,
                                       0x1000408102040 , 0x102000810204080 , 0x204001020408000 , 0x408002040800000 , 0x810004080000000 , 0x1020008000000000 , 0x2040000000000000 , 0x20408102040 ,
                                       0x100040810204080 , 0x200081020408000 , 0x400102040800000 , 0x800204080000000 , 0x1000408000000000 , 0x2000800000000000 , 0x4000000000000000 , 0x2040810204080 ,
                                        0x4081020408000 , 0x8102040800000 , 0x10204080000000 , 0x20408000000000 , 0x40800000000000 , 0x80000000000000 , 0x0 };
/* Blockers tables */

//Starting from Blocker at a1 square
const U64 Blockers_Positive45_Digaonal_SliderUp_Mask[64] = { 0x8040201008040201 , 0x80402010080402 , 0x804020100804 , 0x8040201008 , 0x80402010 , 0x804020 , 0x8040 , 0x80 , 0x4020100804020100 ,
                                                             0x8040201008040200 , 0x80402010080400 , 0x804020100800 , 0x8040201000 , 0x80402000 , 0x804000 , 0x8000 , 0x2010080402010000 ,
                                                             0x4020100804020000 , 0x8040201008040000 , 0x80402010080000 , 0x804020100000 , 0x8040200000 , 0x80400000 , 0x800000 , 0x1008040201000000 ,
                                                             0x2010080402000000 , 0x4020100804000000 , 0x8040201008000000 , 0x80402010000000 , 0x804020000000 , 0x8040000000 , 0x80000000 , 0x804020100000000 ,
                                                             0x1008040200000000 , 0x2010080400000000 , 0x4020100800000000 , 0x8040201000000000 , 0x80402000000000 , 0x804000000000 , 0x8000000000 , 0x402010000000000 ,
                                                             0x804020000000000 , 0x1008040000000000 , 0x2010080000000000 , 0x4020100000000000 , 0x8040200000000000 , 0x80400000000000 , 0x800000000000 , 0x201000000000000 ,
                                                             0x402000000000000 , 0x804000000000000 , 0x1008000000000000 , 0x2010000000000000 , 0x4020000000000000 , 0x8040000000000000 , 0x80000000000000 , 0x100000000000000 ,
                                                             0x200000000000000 , 0x400000000000000 , 0x800000000000000 , 0x1000000000000000 , 0x2000000000000000 , 0x4000000000000000 , 0x8000000000000000 };

const U64 Blockers_Positive45_Digaonal_SliderDw_Mask[64] = { 0x1 , 0x2 , 0x4 , 0x8 , 0x10 , 0x20 , 0x40 , 0x80 , 0x100 ,
                                                             0x201 , 0x402 , 0x804 , 0x1008 , 0x2010 , 0x4020 , 0x8040 , 0x10000 ,
                                                             0x20100 , 0x40201 , 0x80402 , 0x100804 , 0x201008 , 0x402010 , 0x804020 , 0x1000000 ,
                                                             0x2010000 , 0x4020100 , 0x8040201 , 0x10080402 , 0x20100804 , 0x40201008 , 0x80402010 , 0x100000000 ,
                                                             0x201000000 , 0x402010000 , 0x804020100 , 0x1008040201 , 0x2010080402 , 0x4020100804 , 0x8040201008 , 0x10000000000 ,
                                                             0x20100000000 , 0x40201000000 , 0x80402010000 , 0x100804020100 , 0x201008040201 , 0x402010080402 , 0x804020100804 , 0x1000000000000 ,
                                                             0x2010000000000 , 0x4020100000000 , 0x8040201000000 , 0x10080402010000 , 0x20100804020100 , 0x40201008040201 , 0x80402010080402 , 0x100000000000000 ,
                                                             0x201000000000000 , 0x402010000000000 , 0x804020100000000 , 0x1008040201000000 , 0x2010080402010000 , 0x4020100804020100 , 0x8040201008040201 };

//Starting from Blocker at a1 square
const U64 Blockers_Negative45_Diagonal_SliderUp_Mask[64] = { 0x1 , 0x102 , 0x10204 , 0x1020408 , 0x102040810 , 0x10204081020 , 0x1020408102040 , 0x102040810204080 , 0x100 ,
                                                             0x10200 , 0x1020400 , 0x102040800 , 0x10204081000 , 0x1020408102000 , 0x102040810204000 , 0x204081020408000 , 0x10000 ,
                                                             0x1020000 , 0x102040000 , 0x10204080000 , 0x1020408100000 , 0x102040810200000 , 0x204081020400000 , 0x408102040800000 , 0x1000000 ,
                                                             0x102000000 , 0x10204000000 , 0x1020408000000 , 0x102040810000000 , 0x204081020000000 , 0x408102040000000 , 0x810204080000000 , 0x100000000 ,
                                                             0x10200000000 , 0x1020400000000 , 0x102040800000000 , 0x204081000000000 , 0x408102000000000 , 0x810204000000000 , 0x1020408000000000 , 0x10000000000 ,
                                                             0x1020000000000 , 0x102040000000000 , 0x204080000000000 , 0x408100000000000 , 0x810200000000000 , 0x1020400000000000 , 0x2040800000000000 , 0x1000000000000 ,
                                                             0x102000000000000 , 0x204000000000000 , 0x408000000000000 , 0x810000000000000 , 0x1020000000000000 , 0x2040000000000000 , 0x4080000000000000 , 0x100000000000000 ,
                                                             0x200000000000000 , 0x400000000000000 , 0x800000000000000 , 0x1000000000000000 , 0x2000000000000000 , 0x4000000000000000 , 0x8000000000000000 };

const U64 Blockers_Negative45_Diagonal_SliderDw_Mask[64] = { 0x1 , 0x2 , 0x4 , 0x8 , 0x10 , 0x20 , 0x40 , 0x80 , 0x102 ,
                                                             0x204 , 0x408 , 0x810 , 0x1020 , 0x2040 , 0x4080 , 0x8000 , 0x10204 ,
                                                             0x20408 , 0x40810 , 0x81020 , 0x102040 , 0x204080 , 0x408000 , 0x800000 , 0x1020408 ,
                                                             0x2040810 , 0x4081020 , 0x8102040 , 0x10204080 , 0x20408000 , 0x40800000 , 0x80000000 , 0x102040810 ,
                                                             0x204081020 , 0x408102040 , 0x810204080 , 0x1020408000 , 0x2040800000 , 0x4080000000 , 0x8000000000 , 0x10204081020 ,
                                                             0x20408102040 , 0x40810204080 , 0x81020408000 , 0x102040800000 , 0x204080000000 , 0x408000000000 , 0x800000000000 , 0x1020408102040 ,
                                                             0x2040810204080 , 0x4081020408000 , 0x8102040800000 , 0x10204080000000 , 0x20408000000000 , 0x40800000000000 , 0x80000000000000 , 0x102040810204080 ,
                                                             0x204081020408000 , 0x408102040800000 , 0x810204080000000 , 0x1020408000000000 , 0x2040800000000000 , 0x4080000000000000 , 0x8000000000000000 };
//Starting from Blocker at a1 square
const U64 Blockers_Vertical_SliderUp_Mask[64] = {0x1 , 0x2 , 0x4 , 0x8 , 0x10 , 0x20 , 0x40 , 0x80 , 0x101 ,
                                                 0x202 , 0x404 , 0x808 , 0x1010 , 0x2020 , 0x4040 , 0x8080 , 0x10101 ,
                                                 0x20202 , 0x40404 , 0x80808 , 0x101010 , 0x202020 , 0x404040 , 0x808080 , 0x1010101 ,
                                                 0x2020202 , 0x4040404 , 0x8080808 , 0x10101010 , 0x20202020 , 0x40404040 , 0x80808080 , 0x101010101 ,
                                                 0x202020202 , 0x404040404 , 0x808080808 , 0x1010101010 , 0x2020202020 , 0x4040404040 , 0x8080808080 , 0x10101010101 ,
                                                 0x20202020202 , 0x40404040404 , 0x80808080808 , 0x101010101010 , 0x202020202020 , 0x404040404040 , 0x808080808080 , 0x1010101010101 ,
                                                 0x2020202020202 , 0x4040404040404 , 0x8080808080808 , 0x10101010101010 , 0x20202020202020 , 0x40404040404040 , 0x80808080808080 , 0x101010101010101 ,
                                                 0x202020202020202 , 0x404040404040404 , 0x808080808080808 , 0x1010101010101010 , 0x2020202020202020 , 0x4040404040404040 , 0x8080808080808080 };

const U64 Blockers_Vertical_SliderDw_Mask[64] = { 0x101010101010101 , 0x202020202020202 , 0x404040404040404 , 0x808080808080808 , 0x1010101010101010 , 0x2020202020202020 , 0x4040404040404040 , 0x8080808080808080 , 0x101010101010100 ,
                                                  0x202020202020200 , 0x404040404040400 , 0x808080808080800 , 0x1010101010101000 , 0x2020202020202000 , 0x4040404040404000 , 0x8080808080808000 , 0x101010101010000 ,
                                                  0x202020202020000 , 0x404040404040000 , 0x808080808080000 , 0x1010101010100000 , 0x2020202020200000 , 0x4040404040400000 , 0x8080808080800000 , 0x101010101000000 ,
                                                  0x202020202000000 , 0x404040404000000 , 0x808080808000000 , 0x1010101010000000 , 0x2020202020000000 , 0x4040404040000000 , 0x8080808080000000 , 0x101010100000000 ,
                                                  0x202020200000000 , 0x404040400000000 , 0x808080800000000 , 0x1010101000000000 , 0x2020202000000000 , 0x4040404000000000 , 0x8080808000000000 , 0x101010000000000 ,
                                                  0x202020000000000 , 0x404040000000000 , 0x808080000000000 , 0x1010100000000000 , 0x2020200000000000 , 0x4040400000000000 , 0x8080800000000000 , 0x101000000000000 ,
                                                  0x202000000000000 , 0x404000000000000 , 0x808000000000000 , 0x1010000000000000 , 0x2020000000000000 , 0x4040000000000000 , 0x8080000000000000 , 0x100000000000000 ,
                                                  0x200000000000000 , 0x400000000000000 , 0x800000000000000 , 0x1000000000000000 , 0x2000000000000000 , 0x4000000000000000 , 0x8000000000000000 };
//Starting from Blocker at a1 square
const U64 Blockers_Horizontal_SliderLeft_Mask[64] ={ 0x1 , 0x3 , 0x7 , 0xf , 0x1f , 0x3f , 0x7f , 0xff , 0x100 ,
                                                     0x300 , 0x700 , 0xf00 , 0x1f00 , 0x3f00 , 0x7f00 , 0xff00 , 0x10000 ,
                                                     0x30000 , 0x70000 , 0xf0000 , 0x1f0000 , 0x3f0000 , 0x7f0000 , 0xff0000 , 0x1000000 ,
                                                     0x3000000 , 0x7000000 , 0xf000000 , 0x1f000000 , 0x3f000000 , 0x7f000000 , 0xff000000 , 0x100000000 ,
                                                     0x300000000 , 0x700000000 , 0xf00000000 , 0x1f00000000 , 0x3f00000000 , 0x7f00000000 , 0xff00000000 , 0x10000000000 ,
                                                     0x30000000000 , 0x70000000000 , 0xf0000000000 , 0x1f0000000000 , 0x3f0000000000 , 0x7f0000000000 , 0xff0000000000 , 0x1000000000000 ,
                                                     0x3000000000000 , 0x7000000000000 , 0xf000000000000 , 0x1f000000000000 , 0x3f000000000000 , 0x7f000000000000 , 0xff000000000000 , 0x100000000000000 ,
                                                     0x300000000000000 , 0x700000000000000 , 0xf00000000000000 , 0x1f00000000000000 , 0x3f00000000000000 , 0x7f00000000000000 , 0xff00000000000000 };


const U64 Blockers_Horizontal_SliderRight_Mask[64] = { 0xff , 0xfe , 0xfc , 0xf8 , 0xf0 , 0xe0 , 0xc0 , 0x80 , 0xff00 ,
                                                       0xfe00 , 0xfc00 , 0xf800 , 0xf000 , 0xe000 , 0xc000 , 0x8000 , 0xff0000 ,
                                                       0xfe0000 , 0xfc0000 , 0xf80000 , 0xf00000 , 0xe00000 , 0xc00000 , 0x800000 , 0xff000000 ,
                                                       0xfe000000 , 0xfc000000 , 0xf8000000 , 0xf0000000 , 0xe0000000 , 0xc0000000 , 0x80000000 , 0xff00000000 ,
                                                       0xfe00000000 , 0xfc00000000 , 0xf800000000 , 0xf000000000 , 0xe000000000 , 0xc000000000 , 0x8000000000 , 0xff0000000000 ,
                                                       0xfe0000000000 , 0xfc0000000000 , 0xf80000000000 , 0xf00000000000 , 0xe00000000000 , 0xc00000000000 , 0x800000000000 , 0xff000000000000 ,
                                                       0xfe000000000000 , 0xfc000000000000 , 0xf8000000000000 , 0xf0000000000000 , 0xe0000000000000 , 0xc0000000000000 , 0x80000000000000 , 0xff00000000000000 ,
                                                       0xfe00000000000000 , 0xfc00000000000000 , 0xf800000000000000 , 0xf000000000000000 , 0xe000000000000000 , 0xc000000000000000 , 0x8000000000000000 };

/* Move */

struct Move
{
    /****************************************************************/
    /* Info is a 4-Byte unsigned = 32 bit variable.                 */
    /* The 6 least-significant bits to store : FROM square. (0-63)  */
    /* The next 6 bits to store : TO square. (0-63)                 */
    /* The next 4 bits to store : Promotion piece,if any. (0-13)    */
    /* The next 4 bits to store : Captured Piece,if any. (0-13)     */
    /* The next 4 bits to store : Castling Permissions. (0-15)      */
    /* The next 2 bits to store : Repetition Count. (0-2)           */
    /* The next 2 bits to store : Game Phase. (0-2)                 */
    /* The next 1 bit to store : EnPassent move,if it is. (0-1)     */
    /* The next 1 bit to store : Side. (WHITE-BLACK)                */
    /* The next 1 bit to store : Pawn Start, if it is. (0-1)        */
    /****************************************************************/

    unsigned Info;
    int Score;
    U64 HashKey;

    bool operator!=(Move mov)
    {
        if(Info != mov.Info)
            return true;
        else
            return false;
    }

    /*bool operator==(Move mov)
    {
        if(HashKey == mov.HashKey && Info == mov.Info)
            return true;
        else
            return false;
    }*/
    void operator=(Move mov)
    {
        Info = mov.Info;
        Score = mov.Score;
        HashKey = mov.HashKey;
    }

};


struct Possible_Moves
{
    Move moves[MAX_POSSIBLE_MOVES_SIZE];
    unsigned Count;
};

inline unsigned Set_Move_Info(Move *mov,unsigned FROM,unsigned TO,unsigned Promoted_Piece,unsigned Captured_pc,unsigned Castling_Permisson,unsigned Repitition,unsigned Game_Phase,unsigned EnPassent,unsigned Is_Black_turn,unsigned Is_Pawn_Start)
{
    mov->Info = 0;
    mov->Info |= ((F) | (TO << 6) | (PP << 12) | (CAP << 16) | (CP << 20) | (RP << 24) | (GP << 26) |  (EP << 28) | (IBT << 29) | (IPS << 30));
}

/* De Bruijn BitScan */

const U64 magic = 0x022fdd63cc95386d; // the 4061955.

const unsigned int magictable[64] =
{
    0,  1,  2, 53,  3,  7, 54, 27,
    4, 38, 41,  8, 34, 55, 48, 28,
   62,  5, 39, 46, 44, 42, 22,  9,
   24, 35, 59, 56, 49, 18, 29, 11,
   63, 52,  6, 26, 37, 40, 33, 47,
   61, 45, 43, 21, 23, 58, 17, 10,
   51, 25, 36, 32, 60, 20, 57, 16,
   50, 31, 19, 15, 30, 14, 13, 12,
};

inline unsigned int bitScanForward (U64 b) {
    return magictable[((b&-b)*magic) >> 58];
}

inline void Get_SetBits_Indecies(std::vector<unsigned int> &index,U64 b)
{
    while(b != 0)
    {
        unsigned i = bitScanForward(b);
        index.push_back(i);
        b &= ~SET_SQUARE(i); //clearing that bit
    }
}

/* 64-bit Byte Swap */

inline U64 ByteSwap(U64 b)
{
    #ifdef _GCC_
    return __builtin_bswap64 (b);
    #elif _VCC_
    #include <intrin.h>
    return __int64 _byteswap_uint64(n);
    #else
    return         ((((b) & 0xff00000000000000ull) >> 56) |
                    (((b) & 0x00ff000000000000ull) >> 40) |
                    (((b) & 0x0000ff0000000000ull) >> 24) |
                    (((b) & 0x000000ff00000000ull) >> 8 ) |
                    (((b) & 0x00000000ff000000ull) << 8 ) |
                    (((b) & 0x0000000000ff0000ull) << 24) |
                    (((b) & 0x000000000000ff00ull) << 40) |
                    (((b) & 0x00000000000000ffull) << 56));
    #endif
}


/* Sliders Attacks */

/***************************************************************************/
/* Sliders are any piece that can slide along a row , rank , or a diagonal */
/* and other pieces can block or hinder its movements.                     */
/* Sliders : Bishop , Rook , and Queen                                     */
/***************************************************************************/


inline U64 Get_Slider_Moves_Blocked_AtSq(pieces SliderType,pieces BlockerType,squares SliderSq,squares BlockerSq,U64 SliderMaskedMoves)
{
    U64 Slider_Moves , Mask;

                                          /* Bishop moves */
    if(SliderType == wB || SliderType == bB)
    {
         int Diagonal = GET_DIAGONAL((int)SliderSq,(int)BlockerSq);

        if(SliderMaskedMoves == FULL_BOARD)
            Slider_Moves = Bishop_Moves[SliderSq];
        else if(SliderMaskedMoves == 0)
            return 0;
        else
            Slider_Moves = SliderMaskedMoves;


        if(Diagonal == POSITIVE45_DIAGONAL && SliderSq > BlockerSq)
            Mask = Blockers_Positive45_Digaonal_SliderUp_Mask[BlockerSq] | Negative45_Line_Mask[SliderSq];
        else if(Diagonal == POSITIVE45_DIAGONAL && SliderSq < BlockerSq)
            Mask = Blockers_Positive45_Digaonal_SliderDw_Mask[BlockerSq] | Negative45_Line_Mask[SliderSq];
        else if(Diagonal == NEGATIVE45_DIAGONAL && SliderSq > BlockerSq)
            Mask = Blockers_Negative45_Diagonal_SliderUp_Mask[BlockerSq] | Positive45_Line_Mask[SliderSq];
        else
            Mask = Blockers_Negative45_Diagonal_SliderDw_Mask[BlockerSq] | Positive45_Line_Mask[SliderSq];

        Slider_Moves &= Mask;


        //Checking if the slider and blocker of the same color.
        if(GET_PIECE_COLOUR(BlockerType) == GET_PIECE_COLOUR(SliderType))
             Slider_Moves &= ~SET_SQUARE(BlockerSq); // Clear the Blocker square.
    }

                                              /* Rook moves */

    else if(SliderType == wR || SliderType == bR)
    {
        int Axis = GET_AXIS((int)SliderSq,(int)BlockerSq);

        if(SliderMaskedMoves == FULL_BOARD)
            Slider_Moves = Rook_Moves[SliderSq];
        else if(SliderMaskedMoves == 0)
            return 0;
        else
            Slider_Moves = SliderMaskedMoves;


        if(Axis == HORIZONTAL && SliderSq < BlockerSq)
            Mask = Blockers_Horizontal_SliderLeft_Mask[BlockerSq] | Vertical_Line_Mask[SliderSq];
        else if(Axis == HORIZONTAL && SliderSq > BlockerSq)
            Mask = Blockers_Horizontal_SliderRight_Mask[BlockerSq] | Vertical_Line_Mask[SliderSq];
        else if(Axis == VERTICAL && SliderSq < BlockerSq)
            Mask = Blockers_Vertical_SliderUp_Mask[BlockerSq] | Horizontal_Line_Mask[SliderSq];
        else
            Mask = Blockers_Vertical_SliderDw_Mask[BlockerSq] | Horizontal_Line_Mask[SliderSq];

        Slider_Moves &= Mask;

        if(GET_PIECE_COLOUR(BlockerType) == GET_PIECE_COLOUR(SliderType))
            Slider_Moves &= ~SET_SQUARE(BlockerSq); // Clear the Blocker square.

    }

                                              /* Queen moves */

    else if(SliderType == wQ || SliderType == bQ)
    {
        static U64 Bishop_Part , Rook_Part;

        if(SliderMaskedMoves == FULL_BOARD)
            Slider_Moves = Queen_Moves[SliderSq];
        else if(SliderMaskedMoves == 0)
            return 0;
        else
            Slider_Moves = SliderMaskedMoves;

        Bishop_Part = Rook_Part = Slider_Moves;


        if(SliderType == wQ)
        {
            if(ON_HORIZONTAL_LINE(SliderSq,BlockerSq) || ON_VERTICAL_LINE(SliderSq,BlockerSq))
               Rook_Part = Get_Slider_Moves_Blocked_AtSq(wR,BlockerType,SliderSq,BlockerSq,Rook_Part);
            else
               Bishop_Part = Get_Slider_Moves_Blocked_AtSq(wB,BlockerType,SliderSq,BlockerSq,Bishop_Part);

        }

        if(SliderType == bQ)
        {
            if(ON_HORIZONTAL_LINE(SliderSq,BlockerSq) || ON_VERTICAL_LINE(SliderSq,BlockerSq))
               Rook_Part = Get_Slider_Moves_Blocked_AtSq(bR,BlockerType,SliderSq,BlockerSq,Rook_Part);
            else
               Bishop_Part = Get_Slider_Moves_Blocked_AtSq(bB,BlockerType,SliderSq,BlockerSq,Bishop_Part);

        }



        if(Rook_Part == Slider_Moves)
            Slider_Moves = Bishop_Part | (Rook_Moves[SliderSq] & Rook_Part);
        else if(Bishop_Part == Slider_Moves)
            Slider_Moves = Rook_Part | (Bishop_Moves[SliderSq] & Bishop_Part);
    }

     return Slider_Moves;
}


#endif // DEFINITIONS_H_INCLUDED
