#ifndef REVERSI_UTILS_H
#define REVERSI_UTILS_H

#include <iostream>
#include "game_board.h"

namespace reversi {
namespace utils {
template<size_t N>
void PrintGameBoard(const reversi::GameBoard<N> &game_board) {
    using std::cout;
    using std::endl;

    const auto &board = game_board.board();

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            auto status = board[x][y];
            switch (status) {
                case Disk::BLACK:cout << "●";
                    break;
                case Disk::WHITE:cout << "○";
                    break;
                case Disk::EMPTY:cout << " ";
                    break;
            }
        }
        cout << endl;
    }
    cout << "BLACK:" << game_board.count(reversi::Disk::BLACK) << endl;
    cout << "WHITE:" << game_board.count(reversi::Disk::WHITE) << endl << endl;
}

}
}

#endif //REVERSI_UTILS_H
