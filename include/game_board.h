#ifndef REVERSI_GAME_BOARD_H
#define REVERSI_GAME_BOARD_H

#include <array>

namespace reversi {
enum class disk {
    BLACK, WHITE, EMPTY
};

template<size_t N>
class game_board {
public:
    game_board() {
        // 左上の座標
        auto lu_x = N / 2 - 1;
        auto lu_y = N / 2 - 1;

        /*
         * 白黒
         * 黒白
        */

        for (auto &yline: board) {
            for (auto &y : yline) {
                y = disk::EMPTY;
            }
        }

        board[lu_x][lu_y] = disk::BLACK;
        board[lu_x + 1][lu_y] = disk::WHITE;
        board[lu_x][lu_y + 1] = disk::WHITE;
        board[lu_x + 1][lu_y + 1] = disk::BLACK;
    }

    const auto &getBoard() const {
        return board;
    }

private:
    std::array<std::array<disk, N>, N> board;
};
}

#endif //REVERSI_GAME_BOARD_H
