#pragma once
#include "Piece.h"
class Rook :public Piece
{
public:
	Rook(Color color);
	~Rook();

	std::vector<Position> p;

	std::vector<Position> getPossibleMoves() { return p; };
};

