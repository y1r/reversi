#ifndef REVERSI_GAME_BOARD_H
#define REVERSI_GAME_BOARD_H

#include <array>
#include <cassert>

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

    auto getNext() const { return next; }

    bool placeDisk(const int x, const int y) {
        if (board[x][y] != disk::EMPTY) return false;

        bool ok = false;
        using std::cout;
        using std::endl;

        for (int i = 0; i < dxs.size(); i++) {
            auto dx = dxs[i];
            auto dy = dys[i];

            auto xx = x + dx;
            auto yy = y + dy;

            if (!inRange(xx, yy)) continue;

            bool another_disk_is_found = false;

            while (inRange(xx, yy) && board[xx][yy] == getInverse(next)) {
                xx += dx;
                yy += dy;
                another_disk_is_found = true;
            }

            if (another_disk_is_found && inRange(xx, yy) && board[xx][yy] == next) {
                // can place
                ok = true;
                // swap disks

                while (xx != x || yy != y) {

                    board[xx][yy] = next;
                    xx -= dx;
                    yy -= dy;
                }
            }
        }

        if (ok) {
            board[x][y] = next;
            next = getInverse(next);
        }

        return ok;
    }

    auto count(disk disk) const {
        auto sum = 0;

        for (const auto &yline : board)
            for (const auto &y: yline)
                if (y == disk) sum++;

        return sum;
    }

private:
    bool inRange(int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < N;
    }

    disk getInverse(disk disk) {
        assert(disk != disk::EMPTY);

        if (disk == disk::BLACK) return disk::WHITE;
        else return disk::BLACK;
    }

    const std::array<int, 8> dxs = {-1, 0, 1, 1, 1, 0, -1, -1};
    const std::array<int, 8> dys = {-1, -1, -1, 0, 1, 1, 1, 0};

    std::array<std::array<disk, N>, N> board;
    disk next = disk::BLACK;
};
}

#endif //REVERSI_GAME_BOARD_H
