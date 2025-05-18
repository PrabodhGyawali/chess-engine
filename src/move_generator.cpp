#include "move_generator.hpp"
#include "chess_exceptions.h"

using namespace std;

bool is_state_valid(BoardState& state) {
    // TODO: check for invalid board state
    return true;
}

vector<Move> GenerateLegalPawnMoves(BoardState& state, Side side, Square s) {
    vector<Move> legal_moves;
    switch (side)
    {
    // Square before;
	// Square after;
	// Piece piece;
	// MoveType type;
    case WHITE:
        // Check square in front
        if (state.board[s.rank][s.file - 1] == 0) { // TODO: check for boundary case: if at 8th rank / promotion
            legal_moves.push_back(Move{
                .before = Square{
                    .rank = s.rank, 
                    .file = s.file
                }, 
                .after = Square{
                    .rank = s.rank + 1, 
                    .file = s.file
                }
            });
            // Check for double push
            if (s.rank == 2) {
                if (state.board[s.rank + 1][s.file - 1] == 0) {
                    legal_moves.push_back(Move{
                        .before = Square{
                            .rank = s.rank, 
                            .file = s.file
                        }, 
                        .after = Square{
                            .rank = s.rank + 2, 
                            .file = s.file
                        }
                    });
                }
            }
        }
        // TODO: Check for pawn capture

        break;
    default:
        break;
    }
    return legal_moves;
}
vector<Move> GenerateLegalKnightMoves(BoardState& state, Side side);
vector<Move> GenerateLegalBishopMoves(BoardState& state, Side side);
vector<Move> GenerateLegalRookMoves(BoardState& state, Side side);
vector<Move> GenerateLegalQueenMoves(BoardState& state, Side side);
vector<Move> GenerateLegalKingMoves(BoardState& state, Side side);

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
                legal_pawn_moves = GenerateLegalPawnMoves(state, side, Square{.rank = r + 1, .file = c + 1});
                legal_moves.insert(legal_moves.end(), legal_pawn_moves.begin(), legal_pawn_moves.end());
                break;
            case 2:
                legal_knight_moves = GenerateLegalKnightMoves(state, side);
                legal_moves.insert(legal_moves.end(), legal_knight_moves.begin(), legal_knight_moves.end());
                break;
            case 3:
                legal_bishop_moves = GenerateLegalBishopMoves(state, side);
                legal_moves.insert(legal_moves.end(), legal_bishop_moves.begin(), legal_bishop_moves.end());
                break;
            case 4:
                legal_rook_moves = GenerateLegalRookMoves(state, side);
                legal_moves.insert(legal_moves.end(), legal_rook_moves.begin(), legal_rook_moves.end());
                break;
            case 5:
                legal_queen_moves = GenerateLegalQueenMoves(state, side);
                legal_moves.insert(legal_moves.end(), legal_queen_moves.begin(), legal_queen_moves.end());
                break;
            case 6:
                legal_king_moves = GenerateLegalKingMoves(state, side);
                legal_moves.insert(legal_moves.end(), legal_king_moves.begin(), legal_king_moves.end());
                break;
            default:
                throw new InvalidBoardState("Invalid piece on board!");
            }
        }
    }

    return legal_moves;
}

// Function defintion from: https://www.chessprogramming.org/Perft
vector<Move> GenerateLegalMoves(vector<Move>& move_list) {
    
}
