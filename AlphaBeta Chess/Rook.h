#pragma once
#include "Piece.h"
class Rook :public Piece
{
public:
	Rook(Color color);
	~Rook();

	int getValue() {
		return 5;
	}

	Rook(const Rook* old_obj) :Piece(old_obj->color) {}

	std::vector<Position*> getPossibleMoves(int x, int y);
};

