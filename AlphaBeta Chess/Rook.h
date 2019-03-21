#pragma once
#include "Piece.h"
class Rook :public Piece
{
public:
	Rook(Color color);
	~Rook();

	int value = 5;

	std::vector<Position*> getPossibleMoves(int x, int y);
};

