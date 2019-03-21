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
			int kings = 0;
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (gb->pieces[i][j] != nullptr)
						if (dynamic_cast<King*>(gb->pieces[i][j]))
							kings++;
				}
			}

			if (kings < 2)
				gameOver(BLACK);

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
			int xdest = 0 , ydest = 0;
			AlphaBetaPruning* ab = new AlphaBetaPruning(*gb, xdest, ydest);
			Position* p = ab->getOptimalMove();
			gb->move(p->x, p->y, xdest, ydest);
			whitesTurn = true;
			delete ab;
		}
		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}
}

void Window::gameOver(Color color){
	running = false;
}
