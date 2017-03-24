#include <iostream>
#include <time.h>
#include "Player.hh"
#include "Map.hh" 
#include <stdlib.h>


int difi;



int dificultad(int& numRows, int& numColumns) {
	int nRows = 5;
	int nColumns = 5;

	difi = 0;
	while (difi != 1 && difi != 2 && difi != 3) {
	
	
		std::cout << "Selecciona la dificultad:\n 1: Easy\n 2: Medium\n 3: Hard\n" << std::endl;
		
		std::cin >> difi;

		if (difi != 1 && difi != 2 && difi != 3) {
			std::cout << "debes elegir un numero del 1 al 3!!" << std::endl;
		}
	
	}
	
	
	 numRows = rand() % (nRows * difi) + (nRows * difi);
	 numColumns = rand() % (nColumns * difi) + (nColumns * difi);
	 return difi;
} 



void main()
{

	srand(time(nullptr));
	int numColumns, numRows;
	int Player1PosX;
	int  Player1PosY;
	bool GameOver = true;
	srand(time(nullptr));


	dificultad(numColumns, numRows);

	// Generant joc 

	Map mapita = Map(numColumns, numRows);					//Reserva memoria dinamica y la llena de '.'
	player p1 = player(numRows, numColumns);				//Inicialitza l'objecte p1

	
	while (GameOver) {
		std::cout << "Selecciona la dificultad:\n 1: Easy\n 2: Medium\n 3: Hard\n" << std::endl;
		int x_old = p1.PlayerPosX;
		int y_old = p1.PlayerPosY;
		mapita.updateBox(p1.PlayerPosX, p1.PlayerPosY, '@');
		mapita.drawMap();
		bool pressed = false;
		while (!pressed)
		p1.moviment(numColumns, numRows, pressed);
		mapita.updateBox(p1.PlayerPosX, p1.PlayerPosY, '@');
			mapita.updateBox(x_old, y_old, '.');
		system("cls");

	}
	std::cout << "Fin Del Juego" << std::endl;
}


