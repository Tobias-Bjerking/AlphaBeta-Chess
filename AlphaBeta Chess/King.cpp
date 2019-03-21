#include "King.h"
#include "Window.h"


King::King(Color color): Piece(color, "Images/King"){
}


King::~King()
{
}

std::vector<Position*> King::getPossibleMoves(int x, int y){
	std::vector<Position*> possiblePositions;
	for (int i = 0 + x; i < 8; i++) {

	}
	
	return possiblePositions;
}
