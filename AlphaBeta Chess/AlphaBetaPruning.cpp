#include "AlphaBetaPruning.h"
#include <iostream>



AlphaBetaPruning::AlphaBetaPruning(GameBoard& board, int& xdest, int& ydest){
	bestPosition = alphaBeta(board, xdest, ydest);
}


AlphaBetaPruning::~AlphaBetaPruning(){
}

Position* AlphaBetaPruning::alphaBeta(GameBoard& board, int& xdest, int& ydest){
	int bestValue = INT_MIN;
	int x = 0, y = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board.pieces[i][j] != nullptr && board.pieces[i][j]->color == BLACK) {
				for (Position* p : board.pieces[i][j]->getPossibleMoves(i, j)) {
					GameBoard& b = *new GameBoard();
					b = board;
					b.move(i, j, p->x, p->y);
					int v = alphaBeta(b, 3, INT_MIN, INT_MAX, false);
					if (v > bestValue) {
						bestValue = v;
						x = i;
						y = j;
						xdest = p->x;
						ydest = p->y;
					}
					delete &b;
				}
			}
		}
	}
	return new Position(x, y);
}


int AlphaBetaPruning::alphaBeta(GameBoard& board, int depth, int alpha, int beta, bool cpuTurn){
	
	if (depth <= 0) {
		int black = board.blackTotal;
		int white = board.whiteTotal;
		return white > black ? white * -1 : black;
	}

	if (cpuTurn) {
		int maxValue = INT_MIN;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board.pieces[i][j] != nullptr && board.pieces[i][j]->color == BLACK) {
					for (Position* p : board.pieces[i][j]->getPossibleMoves(i, j)) {
						GameBoard& gb = *new GameBoard();
						gb = board;
						gb.move(i, j, p->x, p->y);
						int value = alphaBeta(gb, depth - 1, alpha, beta, !cpuTurn);
						maxValue = max(maxValue, value);
						alpha = max(alpha, value);
						delete &gb;
						if (beta <= alpha)
							break;
					}
				}
			}
		}
		return maxValue;
	}
	else {
		int minValue = INT_MAX;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board.pieces[i][j] != nullptr && board.pieces[i][j]->color == WHITE) {
					for (Position* p : board.pieces[i][j]->getPossibleMoves(i, j)) {
						GameBoard& gb = *new GameBoard();
						gb = board;
						gb.move(i, j, p->x, p->y);
						int value = alphaBeta(gb, depth - 1, alpha, beta, !cpuTurn);
						minValue = min(minValue, value);
						beta = min(beta, value);
						delete &gb;
						if (beta <= alpha)
							break;
					}
				}
			}
		}
		return minValue;
	}
}

int AlphaBetaPruning::max(int x, int y){
	return x >= y ? x : y;
}

int AlphaBetaPruning::min(int x, int y){
	return x <= y ? x : y;
}
