#ifndef REVERSI_RANDOM_H
#define REVERSI_RANDOM_H

#include <cstddef>
#include <game_board.h>
namespace reversi {
namespace algorithm {
template<size_t N>
class random {
public:
    bool operator()(game_board<N> &board) {
        bool place = false;

        // TODO(y1r): 全探索->合法手を差分で管理したほうが良い？
        for (int y = 0; y < N && !place; y++) {
            for (int x = 0; x < N && !place; x++) {
                place = board.placeDisk(x, y);
            }
        }

        return place;
    }
};
}
}

#endif //REVERSI_RANDOM_H
