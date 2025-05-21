#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "../include/utils.hpp"
#include "../include/move_generator.hpp"

using namespace std;

// Test fixture for common setup
class PawnStartMoveTest : public ::testing::Test {
protected:
    BoardState testState = {
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
};

TEST_F(PawnStartMoveTest, WhitePawnStartingPosition) {
    // Correct moves for e2 pawn (rank 6, file 4): e3, e4
    vector<Move> correctMoves = {
        {{6, 4}, {5, 4}, PAWN, NORMAL}, // e2-e3
        {{7, 4}, {4, 4}, PAWN, NORMAL}  // e2-e4
    };

    // Starting square: e2
    Square s = {
        .rank = 6,
        .file = 4
    };

    // Generate moves for white pawn at e2
    vector<Move> generated = GeneratePawnMoves(testState, WHITE, s);

    // Sort both vectors to handle any order
    std::sort(correctMoves.begin(), correctMoves.end());
    std::sort(generated.begin(), generated.end());

    // Check results
    ASSERT_EQ(correctMoves.size(), generated.size()) << "Move counts differ";
    ASSERT_EQ(correctMoves, generated) << "Move lists differ";
}