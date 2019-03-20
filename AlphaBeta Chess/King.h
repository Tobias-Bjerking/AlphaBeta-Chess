#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King(Color color);
	~King();

	std::vector<Position> p;

	std::vector<Position> getPossibleMoves() { return p; };
};

