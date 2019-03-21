#include "GameBoard.h"
#include "Window.h"

#include <iostream>

GameBoard::GameBoard(){
}

void GameBoard::setUpBoard() {
	for (int i = 0; i < 8; i++) {
		pieces[1][i] = new Pawn(BLACK);
		pieces[6][i] = new Pawn(WHITE);
	}

	pieces[0][0] = new Rook(BLACK);
	pieces[0][7] = new Rook(BLACK);
	pieces[7][0] = new Rook(WHITE);
	pieces[7][7] = new Rook(WHITE);

	pieces[0][1] = new Knight(BLACK);
	pieces[0][6] = new Knight(BLACK);
	pieces[7][1] = new Knight(WHITE);
	pieces[7][6] = new Knight(WHITE);

	pieces[0][2] = new Bishop(BLACK);
	pieces[0][5] = new Bishop(BLACK);
	pieces[7][2] = new Bishop(WHITE);
	pieces[7][5] = new Bishop(WHITE);

	pieces[0][3] = new Queen(BLACK);
	pieces[7][3] = new Queen(WHITE);

	pieces[0][4] = new King(BLACK);
	pieces[7][4] = new King(WHITE);

	setUpValueBoard();
}

void GameBoard::setUpValueBoard() {
	for (int i = 0; i < 8; i++) {
		value[0][i] = 0;
		value[i][0] = 0;
		value[7][i] = 0;
		value[i][7] = 0;
	}

	for (int i = 1; i < 7; i++) {
		value[1][i] = 1;
		value[i][1] = 1;
		value[6][i] = 1;
		value[i][6] = 1;
	}

	for (int i = 2; i < 6; i++) {
		value[2][i] = 2;
		value[i][2] = 2;
		value[5][i] = 2;
		value[i][5] = 2;
	}

	for (int i = 3; i < 5; i++) {
		value[3][i] = 3;
		value[i][3] = 3;
		value[4][i] = 3;
		value[i][4] = 3;
	}
}

GameBoard::~GameBoard(){
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			delete pieces[i][j];
		}
	}
}

void GameBoard::move(int x, int y){
	if (selected) {
		bool canMove = false;
		std::vector<Position*> poslist = pieces[selected->x][selected->y]->getPossibleMoves(selected->x, selected->y);
		for (Position* p : poslist) {
			if (p->x == x && p->y == y) {
				canMove = true;
				break;
			}
		}
		if (canMove) {
			pieces[x][y] = pieces[selected->x][selected->y];
			pieces[selected->x][selected->y] = nullptr;
			selected = nullptr;
		}
		else {
			selected = nullptr;
		}
	}
	else {
		if (pieces[x][y] != nullptr) {
			selected = new Position(x, y);
		}
	}
}

void GameBoard::drawBoard(){

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			SDL_Rect rect = { j * 64, i * 64, 64, 64 };
			if(j%2 == i%2)
				SDL_SetRenderDrawColor(Window::getInstance().renderer, 255, 255, 255, 255);
			else
				SDL_SetRenderDrawColor(Window::getInstance().renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(Window::getInstance().renderer, &rect);
		}
	}

	if (selected) {
		SDL_Rect rect = { selected->y * 64, selected->x * 64, 64, 64 };
		SDL_SetRenderDrawColor(Window::getInstance().renderer, 255, 223, 0, 255);
		SDL_RenderFillRect(Window::getInstance().renderer, &rect);
		for (Position* p : pieces[selected->x][selected->y]->getPossibleMoves(selected->x, selected->y)) {
			SDL_Rect rect = { p->y * 64, p->x * 64, 64, 64 };
			SDL_SetRenderDrawColor(Window::getInstance().renderer, 46, 139, 87, 255);
			SDL_RenderFillRect(Window::getInstance().renderer, &rect);
		}
	}

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++) {
			if (pieces[i][j]) {
				SDL_Rect rect = { j * 64, i * 64, 64, 64 };
				pieces[i][j]->draw(rect);
			}
		}
	}


}
