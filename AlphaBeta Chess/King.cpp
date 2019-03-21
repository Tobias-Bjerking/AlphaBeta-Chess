#include "King.h"
#include "Window.h"


King::King(Color color): Piece(color, "Images/King"){
}


King::~King()
{
}

std::vector<Position*> King::getPossibleMoves(int x, int y){
	std::vector<Position*> possiblePositions;
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
				if (x + i < 8 && x + i >= 0 && y + j < 8 && y + j >= 0)
					if (Window::getInstance().gb->pieces[x+i][y+j] == nullptr)
						possiblePositions.push_back(new Position(x + i, y + j));
					else if(Window::getInstance().gb->pieces[x + i][y + j]->color != color)
						possiblePositions.push_back(new Position(x + i, y + j));
	
	return possiblePositions;
}
