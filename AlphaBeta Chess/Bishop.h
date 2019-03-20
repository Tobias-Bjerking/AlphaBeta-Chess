#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop(Color color);
	~Bishop();

	std::vector<Position> p;

	std::vector<Position> getPossibleMoves() { return p; };
};

