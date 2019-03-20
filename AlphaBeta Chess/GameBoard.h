#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include <iostream>
#include <vector>
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class GameBoard{

public:

	void run();
	void setUpBoard();

	static GameBoard& getInstance();

	SDL_Renderer* renderer;
	Piece* pieces[8][8];

	~GameBoard();
private:
	GameBoard();


	void drawBoard();



	GameBoard(const GameBoard& other) = delete;
	const GameBoard& operator=(const GameBoard& other) = delete;

	SDL_Window* window;
	int window_width = 512;
	int window_height = 512;
	bool running = true;
	const int tickInterval = 1000 / 30;
};