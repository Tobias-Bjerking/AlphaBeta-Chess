#pragma once
#include "Piece.h"
class Knight : public Piece{
public:
	Knight(Color color);
	~Knight();

	std::vector<Position> p;

	std::vector<Position> getPossibleMoves() { return p; };
};

