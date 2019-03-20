#pragma once
#include "Piece.h"
class Knight : public Piece{
public:
	Knight(Color color);
	~Knight();

	std::vector<Position*> getPossibleMoves(int x, int y);
};

