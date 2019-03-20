#include "Window.h"


using namespace std;
int main(int argc, char** argv) {

	Window& window = Window::getInstance();
	window.setUpBoard();
	window.run();

	return 0;
}