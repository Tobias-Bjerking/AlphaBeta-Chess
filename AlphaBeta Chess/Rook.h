#pragma once
#include "Piece.h"
class Rook :public Piece
{
public:
	Rook(Color color);
	~Rook();

	std::vector<Position*> getPossibleMoves(int x, int y);
};

