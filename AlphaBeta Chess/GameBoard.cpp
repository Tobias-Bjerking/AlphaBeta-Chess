#include "GameBoard.h"



GameBoard::GameBoard(){
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	window = SDL_CreateWindow("Titel", 100, 100, window_width, window_height, 0);
	render = SDL_CreateRenderer(window, -1, 0);
}


GameBoard::~GameBoard(){
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
}

void GameBoard::run(){
	while (running) {
		Uint32 sdlTicks = SDL_GetTicks();
		Uint32 nextTick = sdlTicks + tickInterval;

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				SDL_Quit();
				break;
			}
		}

		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}
}
