#include "Knight.h"
#include "Window.h"


Knight::Knight(Color color) :Piece(color, "Images/Knight"){
}


Knight::~Knight()
{
}

std::vector<Position*> Knight::getPossibleMoves(int x, int y){
	std::vector<Position*> possiblePositions;
	if (x + 2 < 8) {
		if (y + 1 < 8) {
			if (Window::getInstance().gb->pieces[x + 2][y + 1] == nullptr)
				possiblePositions.push_back(new Position(x + 2, y + 1));
			else if (Window::getInstance().gb->pieces[x + 2][y + 1]->color != color)
				possiblePositions.push_back(new Position(x + 2, y + 1));
		}
		if (y - 1 >= 0)
			if (Window::getInstance().gb->pieces[x + 2][y - 1] == nullptr)
				possiblePositions.push_back(new Position(x + 2, y - 1));
			else if (Window::getInstance().gb->pieces[x + 2][y - 1]->color != color)
				possiblePositions.push_back(new Position(x + 2, y - 1));
	}
	if (x - 2 >= 0) {
		if (y + 1 < 8) {
			if (Window::getInstance().gb->pieces[x - 2][y + 1] == nullptr)
				possiblePositions.push_back(new Position(x - 2, y + 1));
			else if (Window::getInstance().gb->pieces[x - 2][y + 1]->color != color)
				possiblePositions.push_back(new Position(x - 2, y + 1));
		}
		if (y - 1 >= 0)
			if (Window::getInstance().gb->pieces[x - 2][y - 1] == nullptr)
				possiblePositions.push_back(new Position(x - 2, y - 1));
			else if (Window::getInstance().gb->pieces[x - 2][y - 1]->color != color)
				possiblePositions.push_back(new Position(x - 2, y - 1));
	}
	if (y + 2 < 8) {
		if (x + 1 < 8) {
			if (Window::getInstance().gb->pieces[x + 1][y + 2] == nullptr)
				possiblePositions.push_back(new Position(x + 1, y + 2));
			else if (Window::getInstance().gb->pieces[x + 1][y + 2]->color != color)
				possiblePositions.push_back(new Position(x + 1, y + 2));
		}
		if (x - 1 >= 0)
			if (Window::getInstance().gb->pieces[x - 1][y + 2] == nullptr)
				possiblePositions.push_back(new Position(x - 1, y + 2));
			else if (Window::getInstance().gb->pieces[x - 1][y + 2]->color != color)
				possiblePositions.push_back(new Position(x - 1, y + 2));
	}
	if (y - 2 >= 0) {
		if (x + 1 < 8) {
			if (Window::getInstance().gb->pieces[x + 1][y - 2] == nullptr)
				possiblePositions.push_back(new Position(x + 1, y - 2));
			else if (Window::getInstance().gb->pieces[x + 1][y - 2]->color != color)
				possiblePositions.push_back(new Position(x + 1, y - 2));
		}
		if (x - 1 >= 0)
			if (Window::getInstance().gb->pieces[x - 1][y - 2] == nullptr)
				possiblePositions.push_back(new Position(x - 1, y - 2));
			else if (Window::getInstance().gb->pieces[x - 1][y - 2]->color != color)
				possiblePositions.push_back(new Position(x - 1, y - 2));
	}
	return possiblePositions;
}
