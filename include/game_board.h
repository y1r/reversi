#ifndef REVERSI_GAME_BOARD_H
#define REVERSI_GAME_BOARD_H

#include <array>
#include <cassert>
#include <vector>
#include <iostream>

namespace reversi {
enum class Disk {
    BLACK = 0,
    WHITE = 1,
    EMPTY = 2
};

Disk InversedDisk(Disk disk) {
    assert(disk != Disk::EMPTY);

    if (disk == Disk::BLACK) return Disk::WHITE;
    else return Disk::BLACK;
}

template<size_t N>
class GameBoard {
public:
    GameBoard() {
        // 左上の座標
        auto lu_x = N / 2 - 1;
        auto lu_y = N / 2 - 1;

        /*
         * 白黒
         * 黒白
        */

        for (auto &yline: board_) {
            for (auto &y : yline) {
                y = Disk::EMPTY;
            }
        }

        board_[lu_x][lu_y] = Disk::BLACK;
        board_[lu_x + 1][lu_y] = Disk::WHITE;
        board_[lu_x][lu_y + 1] = Disk::WHITE;
        board_[lu_x + 1][lu_y + 1] = Disk::BLACK;
    }

    const auto &board() const {
        return board_;
    }

    auto next_disk() const { return next_disk_; }

    bool PlaceDisk(const int x, const int y) {
        if (board_[x][y] != Disk::EMPTY) return false;

        bool ok = false;
        using std::cout;
        using std::endl;

        for (int i = 0; i < dxs.size(); i++) {
            auto dx = dxs[i];
            auto dy = dys[i];

            auto xx = x + dx;
            auto yy = y + dy;

            if (!InRange(xx, yy)) continue;

            bool another_disk_is_found = false;

            while (InRange(xx, yy) && board_[xx][yy] == InversedDisk(next_disk_)) {
                xx += dx;
                yy += dy;
                another_disk_is_found = true;
            }

            if (another_disk_is_found && InRange(xx, yy) && board_[xx][yy] == next_disk_) {
                // can place
                ok = true;
                // swap disks

                while (xx != x || yy != y) {

                    board_[xx][yy] = next_disk_;
                    xx -= dx;
                    yy -= dy;
                }
            }
        }

        if (ok) {
            board_[x][y] = next_disk_;
            next_disk_ = InversedDisk(next_disk_);
        }

        return ok;
    }

    auto count(Disk disk) const {
        auto sum = 0;

        for (const auto &yline : board_)
            for (const auto &y: yline)
                if (y == disk) sum++;

        return sum;
    }

private:
    inline bool InRange(int x, int y) const {
        return 0 <= x && x < N && 0 <= y && y < N;
    }

    const std::array<int, 8> dxs = {-1, 0, 1, 1, 1, 0, -1, -1};
    const std::array<int, 8> dys = {-1, -1, -1, 0, 1, 1, 1, 0};

    std::array<std::array<Disk, N>, N> board_;
    Disk next_disk_ = Disk::BLACK;
};
}

#endif //REVERSI_GAME_BOARD_H
