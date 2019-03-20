#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include <iostream>

class GameBoard{

public:
	GameBoard();
	~GameBoard();

	void run();

	SDL_Window* window;
	SDL_Renderer* renderer;

private:

	void drawBoard();

	int window_width = 576;
	int window_height = 512;
	bool running = true;
	const int tickInterval = 1000 / 30;
};

