#ifndef REVERSI_BASE_H
#define REVERSI_BASE_H

#include "game_board.h"

namespace reversi {
namespace algorithms {
template<size_t N>
class Base {
public:
    virtual bool operator()(GameBoard<N> &board) = 0;
    virtual ~Base() = default;
};

}
}

#endif //REVERSI_BASE_H
