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
	
	Piece* pieces[8][8];
	int value[8][8];

	int blackTotal = 0;
	int whiteTotal = 0;

	GameBoard(const GameBoard& old_obj) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				pieces[i][j] = old_obj.pieces[i][j];
				value[i][j] = old_obj.value[i][j];
			}
		}
		blackTotal = old_obj.blackTotal;
		whiteTotal = old_obj.whiteTotal;
	}

	GameBoard();
	~GameBoard();
private:
	Position* selected = nullptr;
	void setUpValueBoard();


};