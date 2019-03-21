#include "Rook.h"
#include "Window.h"



Rook::Rook(Color color):Piece(color, "Images/Rook"){
}


Rook::~Rook()
{
}

std::vector<Position*> Rook::getPossibleMoves(int x, int y){
	std::vector<Position*> possiblePositions;
	
	for (int i = x + 1; i < 8; i++) {
		if (Window::getInstance().gb->pieces[i][y] == nullptr)
			possiblePositions.push_back(new Position(i, y));
		else if (Window::getInstance().gb->pieces[i][y]->color != color) {
			possiblePositions.push_back(new Position(i, y));
			break;
		}
		else
			break;
	}
	for (int i = x - 1; i >= 0; i--) {
		if (Window::getInstance().gb->pieces[i][y] == nullptr)
			possiblePositions.push_back(new Position(i, y));
		else if (Window::getInstance().gb->pieces[i][y]->color != color) {
			possiblePositions.push_back(new Position(i, y));
			break;
		}
		else
			break;
	}
	for (int i = y + 1; i < 8; i++) {
		if (Window::getInstance().gb->pieces[x][i] == nullptr)
			possiblePositions.push_back(new Position(x, i));
		else if (Window::getInstance().gb->pieces[x][i]->color != color) {
			possiblePositions.push_back(new Position(x, i));
			break;
		}
		else
			break;
	}
	for (int i = y - 1; i >= 0; i--) {
		if (Window::getInstance().gb->pieces[x][i] == nullptr)
			possiblePositions.push_back(new Position(x, i));
		else if (Window::getInstance().gb->pieces[x][i]->color != color) {
			possiblePositions.push_back(new Position(x, i));
			break;
		}
		else
			break;
	}

	return possiblePositions;
}
