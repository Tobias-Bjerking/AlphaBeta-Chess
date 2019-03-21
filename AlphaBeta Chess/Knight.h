#pragma once
#include "Piece.h"
class Knight : public Piece{
public:
	Knight(Color color);
	~Knight();


	int getValue() {
		return 3;
	}

	Knight(const Knight* old_obj) :Piece(old_obj->color) {}

	std::vector<Position*> getPossibleMoves(int x, int y);
};

