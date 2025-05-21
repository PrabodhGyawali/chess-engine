#include "../include/move_generator.hpp"
#include "chess_exceptions.h"

using namespace std;

bool is_state_valid(BoardState& state) {
    // TODO: check for invalid board state
    return true;
}

/** Helper Functions */
bool is_edge(Square s) {
    /** Is edge inside 6x6 box */
}

vector<Move> GeneratePawnMoves(BoardState& state, Side side, Square s) {
    vector<Move> legal_moves;
    int dir = (side == WHITE) ? -1 : 1;
    int start_row = (side == WHITE) ? 6 : 1;
    int row = s.rank;
    int col = s.file;

    int next_row = row + dir;
    if (next_row >= 0 && next_row < 8 && state.board[next_row][col] == 0) {
        legal_moves.push_back(Move{
            .before = s,
            .after = Square{.rank = next_row, .file = col},
            .piece = PAWN,
            .type = NORMAL
        });
    }

    if (row == start_row) {
        int double_next_row = row + 2 * dir;
        if (double_next_row >= 0 && double_next_row < 8 && state.board[double_next_row][col] == 0 && state.board[next_row][col] == 0) {
            legal_moves.push_back(Move{
                .before = s,
                .after = Square{.rank = double_next_row, .file = col},
                .piece = PAWN,
                .type = NORMAL
            });
        }
    }

    // #TODO: Capture logic
    // #TODO: En passant logic

    return legal_moves;
}

vector<Move> GenerateLegalKnightMoves(BoardState& state, Side side, Square s);
vector<Move> GenerateLegalBishopMoves(BoardState& state, Side side, Square s);
vector<Move> GenerateLegalRookMoves(BoardState& state, Side side, Square s);
vector<Move> GenerateLegalQueenMoves(BoardState& state, Side side, Square s);
vector<Move> GenerateLegalKingMoves(BoardState& state, Side side, Square s);

// Initial Function definition
vector<Move> GenerateLegalMoves(BoardState& state, Side side) {
    vector<Move> legal_moves = vector<Move>(0);

    vector<Move> legal_pawn_moves, legal_knight_moves, legal_bishop_moves,
                legal_rook_moves, legal_queen_moves, legal_king_moves; 

    int multiplier = 1;

    if (!is_state_valid(state))
        throw new InvalidBoardState("Invalid board state");
    
    if (side == BLACK)
        multiplier = -1;
    
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            switch (multiplier * state.board[r][c])
            {
            case 1:
                legal_pawn_moves = GeneratePawnMoves(state, side, Square{.rank = r, c});
                legal_moves.insert(legal_moves.end(), legal_pawn_moves.begin(), legal_pawn_moves.end());
                break;
            // case 2:
            //     legal_knight_moves = GenerateLegalKnightMoves(state, side, Square{.rank = r, c});
            //     legal_moves.insert(legal_moves.end(), legal_knight_moves.begin(), legal_knight_moves.end());
            //     break;
            // case 3:
            //     legal_bishop_moves = GenerateLegalBishopMoves(state, side, Square{.rank = r, c});
            //     legal_moves.insert(legal_moves.end(), legal_bishop_moves.begin(), legal_bishop_moves.end());
            //     break;
            // case 4:
            //     legal_rook_moves = GenerateLegalRookMoves(state, side, Square{.rank = r, c});
            //     legal_moves.insert(legal_moves.end(), legal_rook_moves.begin(), legal_rook_moves.end());
            //     break;
            // case 5:
            //     legal_queen_moves = GenerateLegalQueenMoves(state, side, Square{.rank = r, c});
            //     legal_moves.insert(legal_moves.end(), legal_queen_moves.begin(), legal_queen_moves.end());
            //     break;
            // case 6:
            //     legal_king_moves = GenerateLegalKingMoves(state, side, Square{.rank = r, c});
            //     legal_moves.insert(legal_moves.end(), legal_king_moves.begin(), legal_king_moves.end());
            //     break;
            default:
                throw new InvalidBoardState("Invalid piece on board!");
            }
        }
    }

    return legal_moves;
}

// Function defintion from: https://www.chessprogramming.org/Perft
// vector<Move> GenerateLegalMoves(vector<Move>& move_list) {
    
// }
