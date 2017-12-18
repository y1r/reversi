#ifndef REVERSI_USER_H
#define REVERSI_USER_H

#include <cstddef>
#include "game_board.h"
#include "base.h"
namespace reversi {
namespace algorithms {
template<size_t N>
class User : public Base<N> {
public:
    bool operator()(GameBoard<N> &game_board) override {
        /* check skip is necessary */
        {
            bool ok = false;
            for (int x = 0; x < N; x++)
                for (int y = 0; y < N; y++)
                    ok |= game_board.CanPlaceDisk(x, y);

            if (!ok) return false;
        }

        int x, y;
        std::cin >> x >> y;

        while (!game_board.CanPlaceDisk(x, y) && !std::cin.eof()) {
            std::cout << "Cannot place your disk on " << x << "," << y << std::endl;
            std::cin >> x >> y;
        }

        if (game_board.CanPlaceDisk(x, y)) {
            game_board.PlaceDisk(x, y);
            return true;
        } else
            return false;
    }
};
}
}

#endif //REVERSI_USER_H
