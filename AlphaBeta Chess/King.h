#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King(Color color);
	~King();

	int getValue() {
		return 100000;
	}

	King(const King* old_obj) :Piece(old_obj->color) {}

	std::vector<Position*> getPossibleMoves(int x, int y);
};

