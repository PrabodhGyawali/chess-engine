#include <unistd.h> 

enum Side { WHITE, BLACK };
enum Piece {PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING};
enum MoveType {NORMAL, CAPTURE, EN_PASSANT, CHECK, PROMOTION};

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

struct Square {
	uint8_t rank;
	uint8_t file;
}; // TODO: perhaps use smaller datatype as only need to fit: 8 vals: 3 bits 


struct Move {
	Square before;
	Square after;
	Piece piece;
	MoveType type;
};
