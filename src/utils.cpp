#include "../include/utils.hpp"

BoardState startState = {
    .board = {
        {-4, -2, -3, -5, -6, -3, -2, -4}, // rank 8
        {-1, -1, -1, -1, -1, -1, -1, -1}, // rank 7
        { 0,  0,  0,  0,  0,  0,  0,  0}, // rank 6
        { 0,  0,  0,  0,  0,  0,  0,  0}, // rank 5
        { 0,  0,  0,  0,  0,  0,  0,  0}, // rank 4
        { 0,  0,  0,  0,  0,  0,  0,  0}, // rank 3
        { 1,  1,  1,  1,  1,  1,  1,  1}, // rank 2
        { 4,  2,  3,  5,  6,  3,  2,  4}  // rank 1
    },
    .pawn_two_squares_black = {false, false, false, false, false, false, false, false},
    .pawn_two_squares_white = {false, false, false, false, false, false, false, false},
    .can_castle_white = {true, true},
    .can_castle_black = {true, true}
};

