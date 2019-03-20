#include "GameBoard.h"



GameBoard::GameBoard(){
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	window = SDL_CreateWindow("Titel", 100, 100, window_width, window_height, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
}

void GameBoard::setUpBoard(){
	pieces[4][4] = new Pawn(WHITE);
	pieces[3][3] = new Pawn(BLACK);
}


GameBoard::~GameBoard(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			delete pieces[i][j];
		}
	}
}

void GameBoard::run(){
	while (running) {
		Uint32 sdlTicks = SDL_GetTicks();
		Uint32 nextTick = sdlTicks + tickInterval;

		drawBoard();

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				running = false;
				SDL_Quit();
				break;
			}
		}

		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}
}

GameBoard& GameBoard::getInstance() {
	static GameBoard instance;
	return instance;
}

void GameBoard::drawBoard(){
	
	SDL_RenderClear(renderer);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			SDL_Rect rect = { j * 64, i * 64, 64, 64 };
			if(j%2 == i%2)
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			else
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(renderer, &rect);
		}
	}

	SDL_Rect rect = { 8*64, 0, 64, 8*64 };
	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
	SDL_RenderFillRect(renderer, &rect);

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++) {
			if (pieces[i][j]) {
				SDL_Rect rect = { j * 64, i * 64, 64, 64 };
				pieces[i][j]->draw(rect);
			}
		}
	}

	SDL_RenderPresent(renderer);
}
