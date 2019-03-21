#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King(Color color);
	~King();

	int value = INT_MAX;

	std::vector<Position*> getPossibleMoves(int x, int y);
};

