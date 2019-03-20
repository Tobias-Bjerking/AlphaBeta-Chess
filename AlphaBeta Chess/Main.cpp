#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include <iostream>
#include "GameBoard.h"


using namespace std;
int main(int argc, char** argv) {

	GameBoard gb = GameBoard();

	gb.run();

	return 0;
}