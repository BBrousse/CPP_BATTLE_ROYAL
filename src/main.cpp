#include "main.h"

int main(int argc, char **argv) {
	srand(time(NULL));
	CGameCore gameCore = CGameCore::initGame(30,20,20);
	gameCore.printState();
	gameCore.runGame();
	gameCore.cleanGame();
	return 0;
}