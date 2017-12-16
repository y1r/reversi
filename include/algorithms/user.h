#ifndef REVERSI_USER_H
#define REVERSI_USER_H

#include <cstddef>
#include "game_board.h"
namespace reversi {
namespace algorithms {
template<size_t N>
class User {
public:
    bool operator()(GameBoard<N> &game_board) {
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

        while (!game_board.CanPlaceDisk(x, y)) {
            std::cout << "Cannot place your disk on " << x << "," << y << std::endl;
            std::cin >> x >> y;
        }

        game_board.PlaceDisk(x, y);

        return true;
    }

};
}
}

#endif //REVERSI_USER_H
