#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(Color color);
	~Queen();

	int value = 9;

	std::vector<Position*> getPossibleMoves(int x, int y);
};

