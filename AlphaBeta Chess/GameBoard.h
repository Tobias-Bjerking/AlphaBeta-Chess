#pragma once

#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class GameBoard{

public:

	void setUpBoard();
	void move(int x, int y);
	void drawBoard();

	
	Piece* pieces[8][8];

	GameBoard();
	~GameBoard();
private:
	Position* selected = nullptr;


};