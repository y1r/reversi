#include <iostream>

#include "utils.h"
#include "algorithms/alpha_beta.h"
#include "algorithms/user.h"
#include "algorithms/random.h"
#include "algorithms/mini_max.h"

using namespace std;
#define N 8

template<typename LAMBDA>
double GetDurationOfExecution(LAMBDA &&executable) {
    using namespace std::chrono;

    auto start = high_resolution_clock::now();
    executable();
    auto end = high_resolution_clock::now();

    return duration_cast<nanoseconds>(end - start).count() * 1e-9;
}

template<size_t BOARD_SIZE, typename Player1, typename Player2>
void Game(Player1 &&p1, Player2 &&p2) {
    using namespace reversi;

    GameBoard<BOARD_SIZE> board;
    utils::PrintGameBoard(board);

    double elapsed_p1 = 0;
    double elapsed_p2 = 0;

    for (int i = 0; i < (BOARD_SIZE * BOARD_SIZE - 4) / 2; i++) {
        elapsed_p1 +=
            GetDurationOfExecution(
                [&p1, &board]() {
                    if (!p1(board)) {
                        board.Skip();
                        cout << "skip BLACK" << endl;
                    }
                });
        reversi::utils::PrintGameBoard(board);

        elapsed_p2 +=
            GetDurationOfExecution(
                [&p2, &board]() {
                    if (!p2(board)) {
                        board.Skip();
                        cout << "skip WHITE" << endl;
                    }
                });
        reversi::utils::PrintGameBoard(board);
    }

    std::cout << "Black_elapsed:" << elapsed_p1 << "[s]" << endl;
    std::cout << "White_elapsed:" << elapsed_p2 << "[s]" << endl;
}

int main(void) {
//    Game<N>(reversi::algorithms::MiniMax<N, 6>(), reversi::algorithms::MiniMax<N, 7>());
    Game<N>(reversi::algorithms::MiniMax<N>(7), reversi::algorithms::AlphaBeta<N>(6));

    return 0;
}
