#include <iostream>
#include <time.h>
#include "Player.hh"
#include "Map.hh" 
using namespace std;

int difi;



int dificultad(int& numRows, int& numColumns) {
	int nRows = 5;
	int nColumns = 5;

	difi = 0;
	while (difi != 1 && difi != 2 && difi != 3) {
	
	
		cout << "Selecciona la dificultad:\n 1: Easy\n 2: Medium\n 3: Hard\n" << endl;
		
		cin >> difi;

		if (difi != 1 && difi != 2 && difi != 3) {
			cout << "debes elegir un numero del 1 al 3!!" << endl;
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


	srand(time(NULL));


	dificultad(numColumns, numRows);
	player p1 = player(numColumns, numRows);
	
	Player1PosX = p1.PlayerPosX;
	Player1PosY = p1.PlayerPosY;

	// Generant mapa 
	Map mapita = Map(numColumns, numRows);
	mapita.drawMap(Player1PosX, Player1PosY, '@');
	mapita.freeMemory();			

												
}