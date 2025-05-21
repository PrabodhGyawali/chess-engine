#pragma once

#include "utils.hpp"
#include <vector>

using namespace std;

/** https://www.chessprogramming.org/Move_Generation 
 * 		- Pseudo-legal 
 * 		- Quiescence search
 * Test using perft function.
*/

// Given a board state return an array of moves
vector<Move> GenerateLegalMoves(BoardState& state, Side side);

vector<Move> GeneratePawnMoves(BoardState& state, Side side, Square s);

vector<Move> GenerateLegalPawnMoves(BoardState& state, Side side, Square s);
vector<Move> GenerateLegalKnightMoves(BoardState& state, Side side, Square s);
vector<Move> GenerateLegalBishopMoves(BoardState& state, Side side, Square s);
vector<Move> GenerateLegalRookMoves(BoardState& state, Side side, Square s);
vector<Move> GenerateLegalQueenMoves(BoardState& state, Side side, Square s);
vector<Move> GenerateLegalKingMoves(BoardState& state, Side side, Square s);

// Chess Programming Wiki related function definition
vector<Move> GenerateLegalMoves(vector<Move>& move_list);

vector<Move> GenerateLegalPawnMoves(vector<Move>& move_list);
vector<Move> GenerateLegalKnightMoves(vector<Move>& move_list);
vector<Move> GenerateLegalBishopMoves(vector<Move>& move_list);
vector<Move> GenerateLegalRookMoves(vector<Move>& move_list);
vector<Move> GenerateLegalQueenMoves(vector<Move>& move_list);
vector<Move> GenerateLegalKingMoves(vector<Move>& move_list);

bool is_state_valid(BoardState& state);