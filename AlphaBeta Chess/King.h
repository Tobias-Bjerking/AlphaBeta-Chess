#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King(Color color);
	~King();

	int getValue() {
		return 100000;
	}

	std::vector<Position*> getPossibleMoves(int x, int y);
};

