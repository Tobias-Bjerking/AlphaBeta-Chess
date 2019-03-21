#include "Pawn.h"
#include "Window.h"


Pawn::Pawn(Color color):Piece(color, "Images/Pawn") {
}


Pawn::~Pawn()
{
}

std::vector<Position*> Pawn::getPossibleMoves(int x, int y){
	std::vector<Position*> possiblePositions;
	if (color == BLACK) {
		if(x == 1 && Window::getInstance().gb->pieces[x + 2][y] == nullptr)
			possiblePositions.push_back(new Position(x + 2, y));
		if(x+1<8 && y-1>=0)
			if (Window::getInstance().gb->pieces[x + 1][y - 1] != nullptr && Window::getInstance().gb->pieces[x + 1][y - 1]->color != color)
				possiblePositions.push_back(new Position(x + 1, y - 1));
		if(x+1<8)
			if (Window::getInstance().gb->pieces[x + 1][y] == nullptr)
				possiblePositions.push_back(new Position(x + 1, y));
		if(x+1<8 && y+1<8)
			if (Window::getInstance().gb->pieces[x + 1][y + 1] != nullptr && Window::getInstance().gb->pieces[x + 1][y + 1]->color != color)
				possiblePositions.push_back(new Position(x + 1, y + 1));
	}
	else {
		if (x == 6 && Window::getInstance().gb->pieces[x - 2][y] == nullptr)
			possiblePositions.push_back(new Position(x - 2, y));
		if(x-1>=0 && y-1>=0)
			if (Window::getInstance().gb->pieces[x - 1][y - 1] != nullptr && Window::getInstance().gb->pieces[x - 1][y - 1]->color != color)
				possiblePositions.push_back(new Position(x - 1, y - 1));
		if(x-1>=0)
			if (Window::getInstance().gb->pieces[x - 1][y] == nullptr)
				possiblePositions.push_back(new Position(x-1, y));
		if(x-1>=0 && y+1<8)
			if (Window::getInstance().gb->pieces[x - 1][y + 1] != nullptr && Window::getInstance().gb->pieces[x - 1][y + 1]->color != color)
				possiblePositions.push_back(new Position(x - 1, y + 1));
	}
	return possiblePositions;
}
