#include "utils.h"
#include <vector>


// Given a board state return an array of moves
std::vector<Move> generate_moves(BoardState state, Side side) {
	std::vector<Move> moves;

	switch (side)
	{
	case BLACK:
		/* code */
		break;
	case WHITE:
		break;
	default:
		break;
	}

	return moves;
}

std::vector<Move> moves = generate_moves(startState, WHITE);