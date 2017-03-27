#include "Map.hh"
#include <iostream>
#include "player.hh"
#include <conio.h>

int a = 0;
int b = 0;
bool GameOver = true;


player::player(int numRows, int numColumns){


	PlayerPosX = std::rand() % numColumns;
	PlayerPosY =  std::rand() % numRows;
	PlayerScore = 0;
	

}


void player::moviment(int nColumns, int nRows, bool& pressed, bool& GameOver){
	
		switch (Input::moviment())
		{
		case Input::Key::W:
			// Referirme a la posicion del array dinamico, y hacer "fila--"
			
			if(PlayerPosX !=0)
			PlayerPosX = PlayerPosX -1;
			
			//mapita.updateBox(p1.PlayerPosX, p1.PlayerPosY, '@');			éstas dos linias deberian ir aquí pero no sabemos como llamar el método "updateBox" de la classe Map en este método de la classe Player :C
			//mapita.updateBox(x_old, y_old, '.');							así pues hemos tenido que implementarlo desdel main


			pressed = true;
			break;
		case Input::Key::S:
			// Referirme a la posicion del array dinamico, y hacer "fila++"
			
			if (PlayerPosX != nColumns - 1)
			PlayerPosX = PlayerPosX + 1;

			//mapita.updateBox(p1.PlayerPosX, p1.PlayerPosY, '@');			éstas dos linias deberian ir aquí pero no sabemos como llamar el método "updateBox" de la classe Map en este método de la classe Player :C
			//mapita.updateBox(x_old, y_old, '.');							así pues hemos tenido que implementarlo desdel main
			pressed = true;
			
			break;
		case Input::Key::D:
			// Referirme a la posicion del array dinamico, y hacer "columna++"
			if (PlayerPosY != nRows - 1)
			PlayerPosY = PlayerPosY + 1;

			//mapita.updateBox(p1.PlayerPosX, p1.PlayerPosY, '@');			éstas dos linias deberian ir aquí pero no sabemos como llamar el método "updateBox" de la classe Map en este método de la classe Player :C
			//mapita.updateBox(x_old, y_old, '.');							así pues hemos tenido que implementarlo desdel main

			pressed = true;
			
			break;
		case Input::Key::A:
			// Referirme a la posicion del array dinamico, y hacer "columna--"
			if (PlayerPosY != 0)
			PlayerPosY = PlayerPosY - 1;

			//mapita.updateBox(p1.PlayerPosX, p1.PlayerPosY, '@');			éstas dos linias deberian ir aquí pero no sabemos como llamar el método "updateBox" de la classe Map en este método de la classe Player :C
			//mapita.updateBox(x_old, y_old, '.');							así pues hemos tenido que implementarlo desdel main
			pressed = true;
			
			break;

		case Input::Key::ESC:

			std::cout << "Ending Game..." << std::endl;
			pressed = true;
			GameOver = true;
			
		default:
			break;
		}
	}
