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

class GameBoard{

public:

	void run();
	void setUpBoard();

	static GameBoard& getInstance();

	SDL_Renderer* renderer;

	~GameBoard();
private:
	GameBoard();


	void drawBoard();

	Piece* pieces[8][8];


	GameBoard(const GameBoard& other) = delete;
	const GameBoard& operator=(const GameBoard& other) = delete;

	SDL_Window* window;
	int window_width = 576;
	int window_height = 512;
	bool running = true;
	const int tickInterval = 1000 / 30;
};