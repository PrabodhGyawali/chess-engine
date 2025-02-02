#include <unistd.h> 

enum Side { WHITE, BLACK };

struct BoardState {
	char board[8][8];
	bool pawn_two_squares_black[8];
	bool pawn_two_squares_white[8];
	bool can_castle_white[2];
	bool can_castle_black[2];
};

BoardState startState = {
	.board = {
		{-4, -2, -3, -5, -6, -3, -2, -4},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{ 0,  0,  0,  0,  0,  0,  0,  0},
		{ 0,  0,  0,  0,  0,  0,  0,  0},
		{ 0,  0,  0,  0,  0,  0,  0,  0},
		{ 0,  0,  0,  0,  0,  0,  0,  0},
		{ 1,  1,  1,  1,  1,  1,  1,  1},
		{ 4,  2,  3,  5,  6,  3,  2,  4}
	},
	.pawn_two_squares_black = {false, false, false, false, false, false, false, false},
	.pawn_two_squares_white = {false, false, false, false, false, false, false, false},
	.can_castle_white = {true, true},
	.can_castle_black = {true, true}
};


/** 
 * Before & after are numbers between 0 & 63
 */
struct Move {
	__uint8_t before;
	__uint8_t after;
};
