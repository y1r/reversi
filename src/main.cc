#include <iostream>
#include <array>
#include <getopt.h>

#include "algorithms/base.h"
#include "algorithms/alpha_beta.h"
#include "algorithms/mini_max.h"
#include "algorithms/random.h"
#include "algorithms/user.h"

#include "utils.h"

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

    std::cout << "BLACK:●" << std::endl;
    std::cout << "WHITE:○" << std::endl;

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

void usage(int argc, char *argv[]) {
    const char *str =
        " [BLACK] [WHITE]\n"
            "[BLACK|WHITE]\n"
            "\t -a [search_depth]; alphabeta-method\n"
            "\t -m [search_depth]; minimax-method\n"
            "\t -u; user\n"
            "\t -r; random\n";

    std::cout << argv[0] << str << std::endl;
}

int main(int argc, char *argv[]) {
    int player_i = 0;
    std::array<reversi::algorithms::Base<N> *, 2> player = {{nullptr, nullptr}};
    const char *optstring = "a:m:ur";
    int opt;
    opterr = 0;

    while ((opt = getopt(argc, argv, optstring)) != -1 && player_i != 2) {
        switch (opt) {
            case 'a': {
                int depth = atoi(optarg);
                assert(depth >= 1);
                player[player_i] = new reversi::algorithms::AlphaBeta<N>(depth);
                break;
            }
            case 'm': {
                int depth = atoi(optarg);
                assert(depth >= 1);
                player[player_i] = new reversi::algorithms::MiniMax<N>(depth);
                break;
            }
            case 'u':player[player_i] = new reversi::algorithms::User<N>();
                break;
            case 'r':player[player_i] = new reversi::algorithms::Random<N>();
                break;
            default:usage(argc, argv);
                return EXIT_FAILURE;
        }
        player_i++;
    }

    if (player_i != 2) {
        usage(argc, argv);
        return EXIT_FAILURE;
    }

    Game<N>(*player[0], *player[1]);

    delete player[0], player[1];

    return EXIT_SUCCESS;
}
