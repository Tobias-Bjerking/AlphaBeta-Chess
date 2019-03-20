#include "Bishop.h"
#include "Window.h"



Bishop::Bishop(Color color): Piece(color, "Images/Bishop"){
}


Bishop::~Bishop()
{
}

std::vector<Position*> Bishop::getPossibleMoves(int x, int y){
	std::vector<Position*> possiblePositions;
	if (color == BLACK) {

		if (Window::getInstance().gb->pieces[x - 1][y + 1] != nullptr && Window::getInstance().gb->pieces[x - 1][y + 1]->color != color)
			possiblePositions.push_back(new Position(x - 1, y + 1));
		possiblePositions.push_back(new Position(x, y + 1));
		if (Window::getInstance().gb->pieces[x + 1][y + 1] != nullptr && Window::getInstance().gb->pieces[x + 1][y + 1]->color != color)
			possiblePositions.push_back(new Position(x + 1, y + 1));
	}
	else {
		if (Window::getInstance().gb->pieces[x - 1][y - 1] != nullptr && Window::getInstance().gb->pieces[x - 1][y - 1]->color != color)
			possiblePositions.push_back(new Position(x - 1, y - 1));
		possiblePositions.push_back(new Position(x, y - 1));
		if (Window::getInstance().gb->pieces[x + 1][y - 1] != nullptr && Window::getInstance().gb->pieces[x + 1][y - 1]->color != color)
			possiblePositions.push_back(new Position(x + 1, y - 1));
	}
	return possiblePositions;
}
