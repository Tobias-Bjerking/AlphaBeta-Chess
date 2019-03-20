#pragma once
#include "Piece.h"
class Pawn :public Piece{
public:
	Pawn(Color color);
	~Pawn();

	std::vector<Position*> getPossibleMoves(int x, int y);

};