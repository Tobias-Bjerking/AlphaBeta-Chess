#pragma once
#include "Piece.h"
class Pawn :public Piece{
public:
	Pawn(Color color);
	~Pawn();

	int value = 1;

	std::vector<Position*> getPossibleMoves(int x, int y);

};