#include "Queen.h"
#include "Window.h"



Queen::Queen(Color color): Piece(color, "Images/Queen"){
}


Queen::~Queen()
{
}

std::vector<Position*> Queen::getPossibleMoves(int x, int y){
	std::vector<Position*> possiblePositions;
	for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++) {
		if (Window::getInstance().gb->pieces[i][j] == nullptr)
			possiblePositions.push_back(new Position(i, j));
		else if (Window::getInstance().gb->pieces[i][j]->color != color) {
			possiblePositions.push_back(new Position(i, j));
			break;
		}
		else
			break;
	}

	for (int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--) {
		if (Window::getInstance().gb->pieces[i][j] == nullptr)
			possiblePositions.push_back(new Position(i, j));
		else if (Window::getInstance().gb->pieces[i][j]->color != color) {
			possiblePositions.push_back(new Position(i, j));
			break;
		}
		else
			break;
	}

	for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++) {
		if (Window::getInstance().gb->pieces[i][j] == nullptr)
			possiblePositions.push_back(new Position(i, j));
		else if (Window::getInstance().gb->pieces[i][j]->color != color) {
			possiblePositions.push_back(new Position(i, j));
			break;
		}
		else
			break;
	}

	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
		if (Window::getInstance().gb->pieces[i][j] == nullptr)
			possiblePositions.push_back(new Position(i, j));
		else if (Window::getInstance().gb->pieces[i][j]->color != color) {
			possiblePositions.push_back(new Position(i, j));
			break;
		}
		else
			break;
	}

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
