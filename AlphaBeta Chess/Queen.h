#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(Color color);
	~Queen();

	std::vector<Position*> getPossibleMoves(int x, int y);
};

