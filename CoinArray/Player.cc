#include "Map.hh"
#include <iostream>
#include "player.hh"

player::player(int Player_PosX, int Player_PosY, int _score) {

	PlayerPosX = Player_PosX;
	PlayerPosY = Player_PosY;
	PlayerScore = _score;

}

void player::PlayerInit(int numRows , int numColumns, int &Player_PosX, int &Player_PosY) {

	Player_PosX = std::rand() % numRows;
	Player_PosY = std::rand() % numColumns;

}