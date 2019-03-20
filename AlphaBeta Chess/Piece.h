#pragma once

#include "Position.h"
#include <vector>

enum Color { WHITE, BLACK };
class Piece
{
public:
	Piece(Color color);
	~Piece();

	virtual std::vector<Position> getPossibleMoves() = 0;
private:
	Color color;
	
};

