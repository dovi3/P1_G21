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
	int numColumns, numRows;
	int Player1PosX;
	int  Player1PosY;


	srand(time(nullptr));


	dificultad(numColumns, numRows);

	// Generant joc 
	Map mapita = Map(numColumns, numRows);			//Reserva memoria dinamica y la llena de '.'
	player p1 = player(numColumns, numRows);				//Inicialitza l'objecte p1

	while (true) {
		mapita.updateBox(p1.PlayerPosX, p1.PlayerPosY, '@');
		mapita.drawMap();
		bool pressed = false;
		
		while(!pressed)
		
		p1.moviment(1, 1, pressed);
		mapita.updateBox(p1.PlayerPosX, p1.PlayerPosY, '@');
		
		system("cls");
	}
}


/*

	Player1PosX = p1.PlayerPosX;
	Player1PosY = p1.PlayerPosY;
	
	mapita.updateBox(Player1PosX, Player1PosY, '@');   
	mapita.drawMap();
	


	


	
		system("cls");
		std::cout << p1.PlayerPosX << ' ' << p1.PlayerPosY << std::endl;

		
		

			mapita.updateBox(old_x, old_y, '.');
		
			old_x = Player1PosX;
			old_y = Player1PosY;

			p1.moviment(1, 1);
			mapita.updateBox(p1.PlayerPosX, p1.PlayerPosY, '@');
			mapita.drawMap();
		


	
	
	
	
	mapita.freeMemory();									//Libera la memoria del heap usada por el array dinamico

		*/										
