#include <vector>
#include <stdint.h>
#include "../include/utils.h"


uint64_t Perft(int depth) {
    Move move_list[256];
    int n_moves, i;
    uint32_t nodes = 0;

    if (depth == 0)
        return 1ULL;
    
    n_moves = GenerateLegalMoves(move_list);
    for (i = 0; i < n_moves; i++) {
        MakeMove(move_list[i]);
        nodes += Perft(depth - 1);
        UndoMove(move_list[i]);
    }
    return nodes;
}