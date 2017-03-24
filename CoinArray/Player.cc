#include "Map.hh"
#include <iostream>
#include "player.hh"
#include <conio.h>

int a = 0;
int b = 0;
player::player(int numRows, int numColumns){


	PlayerPosX = std::rand() % numColumns;
	PlayerPosY =  std::rand() % numRows;
	PlayerScore = 0;
	

}





void player::moviment(int nColumns, int nRows, bool& pressed) {
	


		switch (Input::moviment())
		{
		case Input::Key::W:
			// Referirme a la posicion del array dinamico, y hacer "fila--"
			
			if(PlayerPosX !=0)
			PlayerPosX = PlayerPosX -1;
			
			pressed = true;
			break;
		case Input::Key::S:
			// Referirme a la posicion del array dinamico, y hacer "fila++"
			
			if (PlayerPosX != nColumns - 1)
			PlayerPosX = PlayerPosX + 1;
			pressed = true;
			
			break;
		case Input::Key::D:
			// Referirme a la posicion del array dinamico, y hacer "columna++"
			if (PlayerPosY != nRows - 1)
			PlayerPosY = PlayerPosY + 1;

			pressed = true;
			
			break;
		case Input::Key::A:
			// Referirme a la posicion del array dinamico, y hacer "columna--"
			if (PlayerPosY != 0)
			PlayerPosY = PlayerPosY - 1;
			pressed = true;

		/*case Input::Key::ESC:
			
			GameOver = false;		
		break;*/

		default:
			break;
		}
	}
