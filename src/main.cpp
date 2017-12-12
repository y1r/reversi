#include <iostream>
#include <utils.h>

#include "algorithms/random.h"

using namespace std;
#define N 8

int main(void) {
    reversi::GameBoard<N> board;

    reversi::utils::PrintGameBoard(board);

    for (int i = 0; i < N * N - 4; i++) {
        auto random = reversi::algorithm::Random<N>();
        random(board);

        reversi::utils::PrintGameBoard(board);
    }

    return 0;
}
