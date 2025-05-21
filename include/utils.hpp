#pragma once

#include <vector>

using namespace std;

enum Side { WHITE, BLACK };
enum Piece {PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING};
enum MoveType {NORMAL, CAPTURE, EN_PASSANT, CHECK, PROMOTION};

struct BoardState {
	vector<vector<int>> board;
	bool pawn_two_squares_black[8];
	bool pawn_two_squares_white[8];
	bool can_castle_white[2];
	bool can_castle_black[2];
};

struct Square {
	int rank;
	int file;
}; 


struct Move {
	Square before;
	Square after;
	Piece piece;
	MoveType type;

	bool operator==(const Move& other) const {
        return before.rank == other.before.rank &&
               before.file == other.before.file &&
               after.rank == other.after.rank &&
               after.file == other.after.file &&
               piece == other.piece &&
               type == other.type;
    }
	bool operator<(const Move& b) {
		if (before.rank != b.before.rank) return before.rank < b.before.rank;
		if (before.file != b.before.file) return before.file < b.before.file;
		if (after.rank != b.after.rank) return after.rank < b.after.rank;
		if (after.file != b.after.file) return after.file < b.after.file;
		if (piece != b.piece) return piece < b.piece;
		return type < b.type;
	}
};


