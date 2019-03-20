#pragma once

#include "Position.h"
#include <vector>
#include <SDL_image.h>

enum Color { WHITE, BLACK };
class Piece
{
public:
	Piece(Color color, std::string iamgePath);
	~Piece();
	SDL_Texture* texture;

	void draw(SDL_Rect);

	virtual std::vector<Position> getPossibleMoves() = 0;
	Color color;
private:
	
};

