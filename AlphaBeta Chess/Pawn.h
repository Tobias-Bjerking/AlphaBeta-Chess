#pragma once
#include "Piece.h"
class Pawn :public Piece{
public:
	Pawn(Color color);
	~Pawn();
	std::vector<Position> p;

	std::vector<Position> getPossibleMoves() { return p; };

};