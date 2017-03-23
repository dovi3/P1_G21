#include "Map.hh"
#include <iostream>
#include "player.hh"
#include <conio.h>

player::player(int numRows, int numColumns) {

	PlayerPosX = std::rand() % numColumns;
	PlayerPosY = std::rand() % numRows;
	PlayerScore = 0;

}

namespace Input
{
	enum class Key // represents each key that the player can use
	{
		NONE, W, A, S, D, ENTER, ESC
	};

	static Key moviment() // returns the key that has been pressed
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
}



void player::moviment(int nColumns, int nRows, bool& pressed) {


		switch (Input::moviment())
		{
		case Input::Key::W:
			// Referirme a la posicion del array dinamico, y hacer "fila--"
			
			PlayerPosY = PlayerPosY - nRows;

			pressed = true;
			break;
		case Input::Key::S:
			// Referirme a la posicion del array dinamico, y hacer "fila++"

			PlayerPosX = PlayerPosX + nRows;
			pressed = true;
			
			break;
		case Input::Key::D:
			// Referirme a la posicion del array dinamico, y hacer "columna++"

			PlayerPosX = PlayerPosY + 1;
			pressed = true;
			
			break;
		case Input::Key::A:
			// Referirme a la posicion del array dinamico, y hacer "columna--"

			PlayerPosX = PlayerPosY - 1;
			pressed = true;
		break;

		default:
			break;
		}
	}
