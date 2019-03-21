#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop(Color color);
	~Bishop();

	int getValue() {
		return 3;
	}

	Bishop(const Bishop* old_obj) :Piece(old_obj->color) {}

	std::vector<Position*> getPossibleMoves(int x, int y);
};

