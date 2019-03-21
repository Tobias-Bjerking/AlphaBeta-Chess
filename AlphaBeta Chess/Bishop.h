#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop(Color color);
	~Bishop();

	int value = 3;

	std::vector<Position*> getPossibleMoves(int x, int y);
};

