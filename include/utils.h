#ifndef REVERSI_UTILS_H
#define REVERSI_UTILS_H

#include <iostream>
#include "game_board.h"
namespace reversi {
namespace utils {
template<size_t N>
void print_game_board(const reversi::game_board<N> &game_board) {
    using std::cout;
    using std::endl;

    const auto &board = game_board.getBoard();

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            auto status = board[x][y];
            switch (status) {
                case disk::BLACK:cout << "●";
                    break;
                case disk::WHITE:cout << "○";
                    break;
                case disk::EMPTY:cout << " ";
                    break;
            }
        }
        cout << endl;
    }
    cout << "BLACK:" << game_board.count(reversi::disk::BLACK) << endl;
    cout << "WHITE:" << game_board.count(reversi::disk::WHITE) << endl << endl;
}

}
}

#endif //REVERSI_UTILS_H
