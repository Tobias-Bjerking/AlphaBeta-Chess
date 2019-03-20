#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(Color color);
	~Queen();

	std::vector<Position> p;

	std::vector<Position> getPossibleMoves() { return p; };
};

