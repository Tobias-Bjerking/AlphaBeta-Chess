#pragma once

#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include <iostream>

class GameBoard{

public:

	void setUpBoard();
	bool move(int x, int y, Color color);

	void move(int x, int y, int dx, int dy);

	void drawBoard();
	
	Piece* pieces[8][8];
	int value[8][8];

	int blackTotal = 0;
	int whiteTotal = 0;

	GameBoard& operator=(const GameBoard& old_obj) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (old_obj.pieces[i][j] != nullptr) {
					if (dynamic_cast<Pawn*>(old_obj.pieces[i][j])) {
						pieces[i][j] = new Pawn(dynamic_cast<Pawn*>(old_obj.pieces[i][j]));
						value[i][j] = old_obj.value[i][j];
					}
					else if (dynamic_cast<Rook*>(old_obj.pieces[i][j])) {
						pieces[i][j] = new Rook(dynamic_cast<Rook*>(old_obj.pieces[i][j]));
						value[i][j] = old_obj.value[i][j];
					}
					else if (dynamic_cast<Knight*>(old_obj.pieces[i][j])) {
						pieces[i][j] = new Knight(dynamic_cast<Knight*>(old_obj.pieces[i][j]));
						value[i][j] = old_obj.value[i][j];
					}
					else if (dynamic_cast<Bishop*>(old_obj.pieces[i][j])) {
						pieces[i][j] = new Bishop(dynamic_cast<Bishop*>(old_obj.pieces[i][j]));
						value[i][j] = old_obj.value[i][j];
					}
					else if (dynamic_cast<Queen*>(old_obj.pieces[i][j])) {
						pieces[i][j] = new Queen(dynamic_cast<Queen*>(old_obj.pieces[i][j]));
						value[i][j] = old_obj.value[i][j];
					}
					else if (dynamic_cast<King*>(old_obj.pieces[i][j])) {
						pieces[i][j] = new King(dynamic_cast<King*>(old_obj.pieces[i][j]));
						value[i][j] = old_obj.value[i][j];
					}
				}
			}
		}
		blackTotal = old_obj.blackTotal;
		whiteTotal = old_obj.whiteTotal;
		return *this;
	}

	GameBoard();
	~GameBoard();
private:
	Position* selected = nullptr;
	void setUpValueBoard();


};