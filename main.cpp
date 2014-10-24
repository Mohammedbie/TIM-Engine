#include <iostream>
#include "Board.h"
#include "FEN.h"

#include "Move.h"

#include "PERFT.h"

#define FEN "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2"
#define FEN1 "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
#define FEN2 "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1"
#define FEN3 "r2q1rk1/pb2npp1/1ppppn1p/8/3PP1P1/2N2N2/PPPQBP1P/2KR3R w - - 12 1"

#define WHITE_PAWN_FEN "2kq4/2Pp4/8/4pP2/3P4/6p1/7P/4K3 w - e6 0 0"
#define BLACK_PAWN_FEN "2kq4/2Pp4/8/4pP2/2pP4/5pp1/4p2P/3QK3 w - d3 0 0"
#define KNIGHTS_FEN "8/4p3/1P4p1/3N4/5n2/3P4/8/8 b - - 0 0"
#define BISHOPS_FEN "8/8/1Nb2Bn1/8/3bB3/8/6P1/p7 w - - 0 0"
#define ROOKS_FEN "3Q4/8/1N1q1R2/8/1Q1R2P1/8/5P2/8 w - - 0 0"
#define QUEENS_FEN "8/1P3q2/8/3Q4/1q4P1/4N3/2n3Q1/8 w - - 0 0"
#define WHITE_KING_FEN "8/8/7R/3Kp3/2Q1n3/8/8/8 w - - 0 0"
#define BLACK_KING_FEN "8/8/7r/3kP3/2q1N3/8/8/8 w - - 0 0"

#define PERFT_1 "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 0" //Expected moves count = 20
#define PERFT_2 "8/p7/8/1P6/K1k3p1/6P1/7P/8 w - - 0 0" //Expected moves count = 5
#define PERFT_3 "r3k2r/p6p/8/B7/1pp1p3/3b4/P6P/R3K2R w KQkq - 0 0" //Expected moves count = 18
#define PERFT_4 "8/5p2/8/2k3P1/p3K3/8/1P6/8 b - - 0 0" //Expected moves count = 9
#define PERFT_5 "r3k2r/pb3p2/5npp/n2p4/1p1PPB2/6P1/P2N1PBP/R3K2R b KQkq - 0 0" //Expected moves count = 31


using namespace std;

int main()
{
    Board *board = new Board();
    FENparser LoadFENtoBoard(PERFT_1,board);


    U64 Nodes_Count = Perft(board,2);

    cout << "\n\n\n Nodes Count = " << std::dec << Nodes_Count << "\n";

    /*Possible_Moves *moves = new Possible_Moves;
    Generate_All_Moves(board,moves);


    for(unsigned i=0;i<moves->Count;++i)
    {
        cout << "Move : " << std::hex << moves->moves[i].Info << endl;
        cout << "From : " << Squares_Name[GET_FROM_SQUARE(moves->moves[i].Info)] << endl;
        cout << "To : " << Squares_Name[GET_TO_SQUARE(moves->moves[i].Info)] << endl;
        cout << "Is Pawn Start : " << Bools[IS_PAWN_START(moves->moves[i].Info)] << endl;
        cout << "Captured Piece : " << Pieces_Name[GET_CAPTURED_PIECE(moves->moves[i].Info)] << endl;
        cout << "Promoted Piece : " << Pieces_Name[GET_PROMOTED_PIECE(moves->moves[i].Info)] << endl;
        cout << "Castling Permission : " << GET_CASTLING_PERMISSIONS(moves->moves[i].Info) << endl;
        cout << "Repetition Count : " << GET_REPETITION_FROM_MOVE(moves->moves[i].Info) << endl;
        cout << "Game Phase : " << GET_GAME_PHASE(moves->moves[i].Info) << endl;
        cout << "Is EnPassent : " << Bools[IS_ENPASSENT(moves->moves[i].Info)] << endl;
        cout << "Side : " << Colour[GET_SIDE_TO_PLAY(moves->moves[i].Info)] << endl << endl << endl;
    }

    cout <<  std::dec << "Moves count = " << moves->Count << endl;


    delete moves;*/
    delete board;

    return 0;
}
