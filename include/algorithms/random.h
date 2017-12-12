#ifndef REVERSI_RANDOM_H
#define REVERSI_RANDOM_H

#include <cstddef>
#include "game_board.h"
namespace reversi {
namespace algorithms {
template<size_t N>
class Random {
public:
    bool operator()(GameBoard<N> &board) {
        // TODO(y1r): 合法手を差分で管理したほうが良い？
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (board.CanPlaceDisk(x, y)) {
                    board.PlaceDisk(x, y);
                    return true;
                }
            }
        }

        return false;
    }
};
}
}

#endif //REVERSI_RANDOM_H
