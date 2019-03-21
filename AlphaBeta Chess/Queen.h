#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(Color color);
	~Queen();

	int getValue() {
		return 9;
	}

	Queen(const Queen* old_obj) :Piece(old_obj->color) {}

	std::vector<Position*> getPossibleMoves(int x, int y);
};

