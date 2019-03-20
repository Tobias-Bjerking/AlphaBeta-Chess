#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop(Color color);
	~Bishop();

	std::vector<Position*> getPossibleMoves(int x, int y);
};

