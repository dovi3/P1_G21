#include <iostream>
#include <time.h>
#include "Player.hh"
#include "Map.hh" 
using namespace std;

int difi;



void dificultad(int& numRows, int& numColumns) {
	int nRows = 5;
	int nColumns = 10;

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

}



void main()
{
	int numColumns, numRows;
	int PlayerPosX, PlayerPosY;

	srand(time(NULL));


	dificultad(numColumns, numRows);
	/*player p1 = player(2, 2, 0);
	p1.PlayerInit(numColumns, numRows, PlayerPosX, PlayerPosY);*/
	
	// Generant mapa 
	Map mapita = Map(numColumns, numRows);
	mapita.drawMap(3, 3, '$');												
	mapita.freeMemory();													
																			
																			
}