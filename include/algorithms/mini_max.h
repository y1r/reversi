#ifndef REVERSI_MINI_MAX_H
#define REVERSI_MINI_MAX_H

#include <cstddef>
#include "game_board.h"

namespace reversi {
namespace algorithms {

template<size_t N, size_t DEPTH>
class MiniMax {
    using Position = std::pair<int, int>;

public:
    bool operator()(GameBoard<N> &game_board) {
        GameBoard<N> max_board;

        my_disk_ = game_board.next_disk();

        auto result = Search(game_board, DEPTH, false);
        bool found = result.second != Position(-1, -1);

        if (found)
            game_board.PlaceDisk(result.second.first, result.second.second);

        return found;
    }

private:
    Disk my_disk_;

    auto Search(const GameBoard<N> &game_board, int remain_depth, bool min_mode) {
        int good_score = min_mode ? INT_MAX : INT_MIN;
        bool placeable = false;
        int good_x, good_y;

        if (remain_depth == 0)
            return std::make_pair(game_board.count(my_disk_), Position(-1, -1));

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (game_board.CanPlaceDisk(x, y)) {
                    placeable = true;
                    GameBoard<N> next = game_board;
                    next.PlaceDisk(x, y);
                    auto result = Search(next, remain_depth - 1, !min_mode);
                    if (min_mode) {
                        if (result.first < good_score) {
                            good_score = result.first;
                            good_x = x;
                            good_y = y;
                        }
                    } else {
                        if (good_score < result.first) {
                            good_score = result.first;
                            good_x = x;
                            good_y = y;
                        }
                    }
                }
            }
        }

        if (!placeable)
            return std::make_pair(game_board.count(my_disk_), Position(-1, -1));

        return std::make_pair(good_score, Position(good_x, good_y));
    }
};

}
}

#endif //REVERSI_MINI_MAX_H
