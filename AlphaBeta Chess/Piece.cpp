#include "Piece.h"
#include "Window.h"
#include <iostream>


Piece::Piece(Color color, std::string imagePath){
	this->color = color;
	if (color == WHITE) {
		imagePath.append("_W.png");
	}
	else {
		imagePath.append("_B.png");
	}

	SDL_Surface* surface = IMG_Load(imagePath.c_str());

	if (!surface) {
		throw std::runtime_error("Could not load file: " + imagePath);
	}

	texture = SDL_CreateTextureFromSurface(Window::getInstance().renderer, surface);
	SDL_FreeSurface(surface);
}

void Piece::draw(SDL_Rect rect) {
	SDL_RenderCopy(Window::getInstance().renderer, texture, NULL, &rect);
}

Piece::~Piece(){
	SDL_DestroyTexture(texture);
}
