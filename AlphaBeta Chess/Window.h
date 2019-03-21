#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "GameBoard.h"

class Window{
public:

	Window();
	~Window();

	static Window& getInstance() {
		static Window instance;
		return instance;
	};

	void setUpBoard();

	void draw();
	void run();

	bool whitesTurn = true;

	GameBoard* gb;
	SDL_Renderer* renderer;

	void gameOver(Color color);

private:
	Window(const Window& other) = delete;
	const Window& operator=(const Window& other) = delete;

	SDL_Window* window;
	int window_width = 512;
	int window_height = 512;
	bool running = true;
	const int tickInterval = 1000 / 30;

};

