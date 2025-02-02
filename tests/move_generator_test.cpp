#include <gtest/gtest.h>
#include "../include/utils.h"

BoardState createTestPosition() {
    BoardState state = {};

    state.board[1][5] = -6;
    state.board[1][4] = -1;
    state.board[2][6] = -1;
    state.board[4][1] = 1;
    state.board[4][4] = 4;
    state.board[6][2] = 6;

    state.can_castle_black = {false, false};
    state.can_castle_white = {false, false};

    return state;
}

TEST(MoveGeneratorTest, WhiteMoves) {
    BoardState position = createTestPosition();
    std::vector<Move> moves = generate_moves(position, BLACK);

    std::vector<Move> expectedBlackMoves = {
        // Pawn moves
        {12, 20},
        {12, 28},
        {22, 30},
        // King Moves
        {13, 14},
        {13, 6},
        {13, 5},
        {13, 4},
        {13, 21}
    }; // 7, 15, 23, 31 

    // TODO: Get correct values for expectedBlackMoves
}