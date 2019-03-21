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
	bool move(int x, int y, Color color);
	void drawBoard();
	bool runAI();
	
	Piece* pieces[8][8];
	int value[8][8];

	int blackTotal = 0;
	int whiteTotal = 0;

	GameBoard();
	~GameBoard();
private:
	Position* selected = nullptr;
	void setUpValueBoard();


};