#pragma once
#include "Piece.h"
class Pawn :public Piece{
public:

	Pawn(Color color);
	~Pawn();

	int getValue() {
		return 1;
	}

	Pawn(const Pawn* old_obj):Piece(old_obj->color) {}

	std::vector<Position*> getPossibleMoves(int x, int y);

};