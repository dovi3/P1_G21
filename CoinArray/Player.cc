#include "Map.hh"
#include <iostream>
#include "player.hh"

player::player(int numRows, int numColumns) {

	PlayerPosX = std::rand() % numRows;
	PlayerPosY = std::rand() % numColumns;
	PlayerScore = 0;

}

