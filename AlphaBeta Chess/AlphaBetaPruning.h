#pragma once
#include "GameBoard.h"
class AlphaBetaPruning
{
public:
	AlphaBetaPruning(GameBoard* board);
	~AlphaBetaPruning();

	Position* getOptimalMove();

private:
	Position* bestPosition;
};

