#include <iostream>
#include <game_board.h>
#include <utils.h>

using namespace std;
#define N 8

int main(void) {
    reversi::game_board<N> board;

    for (int i = 0; i < 60; i++) {
        bool place = true;
        for (int y = 0; y < N && place; y++) {
            for (int x = 0; x < N && place; x++) {
                place = !board.placeDisk(x, y);
            }
        }
        reversi::utils::print_game_board(board);
        cout << endl;
    }

    return 0;
}
