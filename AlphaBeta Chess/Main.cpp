#include "GameBoard.h"


using namespace std;
int main(int argc, char** argv) {

	GameBoard& gb = GameBoard::getInstance();

	gb.setUpBoard();
	gb.run();

	return 0;
}