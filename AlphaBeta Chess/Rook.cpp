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

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (x + i < 8 && x + i >= 0 && y + j < 8 && y + j >= 0)
				if (Window::getInstance().gb->pieces[x + i][y + j] == nullptr)
					possiblePositions.push_back(new Position(x + i, y + j));
				else if (Window::getInstance().gb->pieces[x + i][y + j]->color != color) {
					possiblePositions.push_back(new Position(x + i, y + j));
					break;
				}
				else
					break;
	return possiblePositions;
}
