#include "Window.h"
#include "AlphaBetaPruning.h"

Window::Window(){
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	window = SDL_CreateWindow("A/B Chess", 100, 100, window_width, window_height, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	gb = new GameBoard();
}


Window::~Window(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
}

void Window::setUpBoard(){
	gb->setUpBoard();
}

void Window::draw(){
	SDL_RenderClear(Window::getInstance().renderer);
	gb->drawBoard();
	SDL_RenderPresent(renderer);
}

void Window::run(){
	while (running) {
		Uint32 sdlTicks = SDL_GetTicks();
		Uint32 nextTick = sdlTicks + tickInterval;
		draw();

		if (whitesTurn) {
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT:
					running = false;
					SDL_Quit();
					break;
	
				case SDL_MOUSEBUTTONDOWN:
					if (event.button.button == SDL_BUTTON_LEFT) {
						int x = event.button.y / 64;
						int y = event.button.x / 64;
						whitesTurn =  !(gb->move(x, y, WHITE));
					}
					break;
				}
			}

		}
		else {
			AlphaBetaPruning* ab = new AlphaBetaPruning(*gb);
			Position* p = ab->getOptimalMove();
			whitesTurn = gb->move(p->x, p->y, BLACK);
			delete ab;
		}
		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}
}
