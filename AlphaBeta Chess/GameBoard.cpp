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
		value[0][i] = 1;
		value[i][0] = 1;
		value[7][i] = 1;
		value[i][7] = 1;
	}

	for (int i = 1; i < 7; i++) {
		value[1][i] = 2;
		value[i][1] = 2;
		value[6][i] = 2;
		value[i][6] = 2;
	}

	for (int i = 2; i < 6; i++) {
		value[2][i] = 3;
		value[i][2] = 3;
		value[5][i] = 3;
		value[i][5] = 3;
	}

	for (int i = 3; i < 5; i++) {
		value[3][i] = 4;
		value[i][3] = 4;
		value[4][i] = 4;
		value[i][4] = 4;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pieces[i][j] != nullptr) {
				if (!dynamic_cast<King*>(pieces[i][j])) {
					if (pieces[i][j]->color == BLACK) {
						blackTotal += pieces[i][j]->getValue() * value[i][j];
					}
					else {
						whiteTotal += pieces[i][j]->getValue() * value[i][j];
					}
				}
				else {
					if (pieces[i][j]->color == BLACK) {
						blackTotal += pieces[i][j]->getValue();
					}
					else {
						whiteTotal += pieces[i][j]->getValue();
					}
				}
			}
		}
	}
}

GameBoard::~GameBoard(){
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			delete pieces[i][j];
		}
	}
}

bool GameBoard::move(int x, int y, Color color){
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
			
			if (!dynamic_cast<King*>(pieces[selected->x][selected->y])) {
				if (pieces[selected->x][selected->y]->color == BLACK) {
					blackTotal -= pieces[selected->x][selected->y]->getValue() * value[selected->x][selected->y];
					blackTotal += pieces[selected->x][selected->y]->getValue() * value[x][y];
				}
				else {
					whiteTotal -= pieces[selected->x][selected->y]->getValue() * value[selected->x][selected->y];
					whiteTotal += pieces[selected->x][selected->y]->getValue() * value[x][y];
				}
			}
			if (pieces[x][y] != nullptr) {
				if (pieces[x][y]->color == BLACK) {
					blackTotal -= pieces[x][y]->getValue() * value[x][y];
				}
				else {
					whiteTotal -= pieces[x][y]->getValue() * value[x][y];
				}
			}
			
			pieces[x][y] = pieces[selected->x][selected->y];
			pieces[selected->x][selected->y] = nullptr;
			selected = nullptr;
			std::cout << "black total: " << blackTotal << std::endl;
			std::cout << "white total: " << whiteTotal << std::endl;

			return true;
		}
		else {
			selected = nullptr;
		}
	}
	else {
		if (pieces[x][y] != nullptr && pieces[x][y]->color == color) {
			selected = new Position(x, y);
		}
	}
	return false;
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

bool GameBoard::runAI(){
	return true;
}
