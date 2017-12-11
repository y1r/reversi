#ifndef REVERSI_UTILS_H
#define REVERSI_UTILS_H

#include <iostream>
#include "game_board.h"
namespace reversi {
namespace utils {
template<size_t N>
void print_game_board(const reversi::game_board<N> &board) {
    using std::cout;
    using std::endl;

    for (const auto &yline : board.getBoard()) {
        for (const auto &y : yline) {
            cout << (int) y;
        }
        cout << endl;
    }
}

}
}

#endif //REVERSI_UTILS_H
