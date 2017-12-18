# Reversi
Implementation of Reversi/Othello Game in C++14.

## Implemented Algorithms
- Mini-Max Method
- Alpha-Beta Method
- User (stdin)
- Random (select first-accetable 

## How to Use
```sh
git clone https://github.com/y1r/reversi
cd reversi
cmake .
make
./reversi -a 8 -m 7
# This means "run reversi with alpha-beta(depth=8) and MiniMax(depth=7)"
```

```
./reversi [BLACK] [WHITE]
[BLACK|WHITE]
         -a [search_depth]; alphabeta-method
         -m [search_depth]; minimax-method
         -u; user
         -r; random
```
