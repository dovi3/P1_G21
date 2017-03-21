#include "CoinRace.hh"
#include <conio.h>


namespace Input
{
	enum class Key // represents each key that the player can use
	{
		NONE, W, A, S, D, ENTER, ESC
	};	static Key getKey() // returns the key that has been pressed
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 87: case 119:
				return Key::W; // w and W
			case 65: case 97:
				return Key::A; // a and A
			case 83: case 115:
				return Key::S; // s and S
			case 68: case 100:
				return Key::D; // d and D
			case 13:
				return Key::ENTER; // carriage return
			case 27:
				return Key::ESC; // escape
			}
		}
		return Key::NONE;
	}
};

// Constructor
player::player() {

	
}

void player::InitPlayer(int &PlayerPosX, int &PlayerPosY, int CoinPosX, int CoinPosY) {

	//Si aquesta posició coincideix amb la d'un coin, torna a inicialitzar la posició

	do
	{
		PlayerPosX = rand(); //%// NUM_COLUMNS;
		PlayerPosX = rand(); //%// NUM_ROWS;

	} while (PlayerPosX != CoinPosX && PlayerPosY != CoinPosY);
	

	

}
void player::movimiento() {


 }

void player::PlayerUpdate() {



}

void main() {

	srand(time(NULL));

	player p1;

	

}