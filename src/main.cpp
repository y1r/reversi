#include <iostream>
#include <game_board.h>
#include <utils.h>

using namespace std;

int main(void) {
    reversi::game_board<8> board;
    reversi::utils::print_game_board(board);

    return 0;
}
