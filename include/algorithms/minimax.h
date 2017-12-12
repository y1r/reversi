#ifndef REVERSI_MINIMAX_H
#define REVERSI_MINIMAX_H

#include <cstddef>
#include "game_board.h"

namespace reversi {
namespace algorithms {

template<size_t N, size_t DEPTH>
class MiniMax {
public:
    bool operator()(GameBoard<N> &game_board) {
        int max_score = INT_MIN;
        GameBoard<N> max_board;
        bool placeable = false;

        my_disk_ = game_board.next_disk();

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (game_board.CanPlaceDisk(x, y)) {
                    std::cout << x << "," << y << std::endl;
                    placeable = true;
                    GameBoard<N> next = game_board;
                    next.PlaceDisk(x, y);
                    int score = search(next, DEPTH, true);
                    std::cout << score << std::endl;
                    if (max_score < score) {
                        max_score = score;
                        max_board = next;
                    }
                }
            }
        }

        if (placeable)
            game_board = max_board;

        return placeable;
    }

private:
    Disk my_disk_;

    int search(const GameBoard<N> &game_board, int remain_depth, bool min_mode) {
        int good_score = min_mode ? INT_MAX : INT_MIN;
        bool placeable = false;

        if (remain_depth == 0)
            return game_board.count(my_disk_);

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (game_board.CanPlaceDisk(x, y)) {
                    placeable = true;
                    GameBoard<N> next = game_board;
                    next.PlaceDisk(x, y);
                    int score = search(next, remain_depth - 1, !min_mode);

                    if (min_mode) {
                        if (score < good_score)
                            good_score = score;
                    } else {
                        if (good_score < score)
                            good_score = score;
                    }
                }
            }
        }

        if (!placeable)
            return game_board.count(my_disk_);

        return good_score;
    }
};

}
}

#endif //REVERSI_MINIMAX_H
