#include <iostream>
#include <time.h>
#include "Player.hh"
#include "Map.hh" 
using namespace std;

int difi, dificultadForm;
int nRows = 5;
int nColumns = 10;


void dificultad() {
	
	difi = 0;
	while (difi != 1 && difi != 2 && difi != 3) {
	
	
		cout << "Selecciona la dificultad:\n 1: Easy\n 2: Medium\n 3: Hard\n" << endl;
		
		cin >> difi;

		if (difi != 1 || difi != 2 || difi != 3) {
			cout << "debes elegir un número del 1 al 3!!" << endl;
		}
	
	}
	
	
	 nRows = nRows * difi;
	 nColumns = nColumns * difi;

}



void main()
{
	srand(time(NULL));
	
	char voidBox = '.';
	char playerSymbol = '@';
	char coinSymbol = '$';


	dificultad();

	Map mapita = Map(nRows, nColumns, voidBox, playerSymbol, coinSymbol);
	mapita.deafultMap();
	mapita.drawMap();
	mapita.freeMemory();


	nRows = 5;
	nColumns = 10;
}