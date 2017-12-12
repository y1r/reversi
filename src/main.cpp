#include <iostream>
#include <game_board.h>
#include <utils.h>
#include <algorithms/random.h>

using namespace std;
#define N 8

int main(void) {
    reversi::game_board<N> board;

    reversi::utils::print_game_board(board);

    for (int i = 0; i < N * N - 4; i++) {
        auto random = reversi::algorithm::random<N>();
        random(board);

        reversi::utils::print_game_board(board);
    }

    return 0;
}
