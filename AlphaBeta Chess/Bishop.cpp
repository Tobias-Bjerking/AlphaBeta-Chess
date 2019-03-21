#include "Bishop.h"
#include "Window.h"



Bishop::Bishop(Color color): Piece(color, "Images/Bishop"){
}


Bishop::~Bishop()
{
}

std::vector<Position*> Bishop::getPossibleMoves(int x, int y){
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

	return possiblePositions;
}
