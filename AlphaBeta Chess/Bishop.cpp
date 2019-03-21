#include "Bishop.h"
#include "Window.h"



Bishop::Bishop(Color color): Piece(color, "Images/Bishop"){
}


Bishop::~Bishop()
{
}

std::vector<Position*> Bishop::getPossibleMoves(int x, int y){
	std::vector<Position*> possiblePositions;
	for (int i = x + 1; i < 8; i++) {
		for (int j = y + 1; j < 8; j++) {
			if (Window::getInstance().gb->pieces[i][j] == nullptr)
				possiblePositions.push_back(new Position(i, j));
			else if (Window::getInstance().gb->pieces[i][j]->color != color) {
				possiblePositions.push_back(new Position(i, j));
				break;
			}
			else
				break;
		}
	}

	for (int i = x + 1; i < 8; i++) {
		for (int j = y - 1; j >=0; j--) {
			if (Window::getInstance().gb->pieces[i][j] == nullptr)
				possiblePositions.push_back(new Position(i, j));
			else if (Window::getInstance().gb->pieces[i][j]->color != color) {
				possiblePositions.push_back(new Position(i, j));
				break;
			}
			else
				break;
		}
	}

	for (int i = x - 1; i >= 0; i--) {
		for (int j = y + 1; j < 8; j++) {
			if (Window::getInstance().gb->pieces[i][j] == nullptr)
				possiblePositions.push_back(new Position(i, j));
			else if (Window::getInstance().gb->pieces[i][j]->color != color) {
				possiblePositions.push_back(new Position(i, j));
				break;
			}
			else
				break;
		}
	}

	for (int i = x - 1; i >= 0; i--) {
		for (int j = y - 1; j >= 0; j--) {
			if (Window::getInstance().gb->pieces[i][j] == nullptr)
				possiblePositions.push_back(new Position(i, j));
			else if (Window::getInstance().gb->pieces[i][j]->color != color) {
				possiblePositions.push_back(new Position(i, j));
				break;
			}
			else
				break;
		}
	}
	return possiblePositions;
}
