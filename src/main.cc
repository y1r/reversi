#include <iostream>
#include <utils.h>

#include "algorithms/user.h"
#include "algorithms/random.h"
#include "algorithms/mini_max.h"

using namespace std;
#define N 8

template<size_t BOARD_SIZE, typename Player1, typename Player2>
void Game(Player1 &&p1, Player2 &&p2) {
    using namespace reversi;

    GameBoard<BOARD_SIZE> board;
    utils::PrintGameBoard(board);

    for (int i = 0; i < (BOARD_SIZE * BOARD_SIZE - 4) / 2; i++) {
        if (!p1(board)) {
            board.Skip();
            cout << "skip BLACK" << endl;
        }

        reversi::utils::PrintGameBoard(board);

        if (!p2(board)) {
            board.Skip();
            cout << "skip WHITE" << endl;
        }

        reversi::utils::PrintGameBoard(board);
    }

}

int main(void) {
//    Game<N>(reversi::algorithms::MiniMax<N, 6>(), reversi::algorithms::MiniMax<N, 7>());
    Game<N>(reversi::algorithms::MiniMax<N, 6>(), reversi::algorithms::User<N>());

    return 0;
}
