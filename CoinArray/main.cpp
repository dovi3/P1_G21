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
	mapita.drawMap(6, 3, '$');												//no tenemos claro si la funcionalidad de este metodo si viene ligada a la clase player,
	mapita.freeMemory();													//es decir, cada vez que el jugador se mueva, la clase player borra la posicion anterior
																			//y coloca el punto como si estubiera vacia la celda, la misma clase Player. O quien coloca el punto
																			// es el metodo "UpdateBox" de la clase Map
	nRows = 5;
	nColumns = 10;
}