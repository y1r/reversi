#include <iostream>
#include <utils.h>

#include "algorithms/random.h"
#include "algorithms/minimax.h"

using namespace std;
#define N 8

int main(void) {
    reversi::GameBoard<N> board;

    reversi::utils::PrintGameBoard(board);

    for (int i = 0; i < (N * N - 4) / 2; i++) {
        auto minimax = reversi::algorithms::MiniMax<N, 7>();

        if (!minimax(board)) {
            board.Skip();
            cout << "skip" << endl;
        }

        reversi::utils::PrintGameBoard(board);

        auto minimax2 = reversi::algorithms::MiniMax<N, 6>();
        if (!minimax2(board)) {
            board.Skip();
            cout << "skip" << endl;
        }
        reversi::utils::PrintGameBoard(board);
    }

    return 0;
}
