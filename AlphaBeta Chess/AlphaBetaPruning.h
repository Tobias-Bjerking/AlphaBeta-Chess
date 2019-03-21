#pragma once
#include "GameBoard.h"
class AlphaBetaPruning{
public:
	AlphaBetaPruning(GameBoard& board);
	~AlphaBetaPruning();




	Position* getOptimalMove() {
		return bestPosition;
	}

private:
	Position* alphaBeta(GameBoard& board);
	int alphaBeta(GameBoard& board, int depth, int alpha, int beta, bool cpuTurn);
	Position* bestPosition;

	int max(int x, int y);
	int min(int x, int y);
};

