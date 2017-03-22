#include <iostream>
#include <stdlib.h>
#include "Map.hh"


char **punteroMapa, nRows, nColumns;

//Constructor de la clase Map
Map::Map(int num_rows, int num_columns, char void_box, char player_symbol, char coin_siymbol) 
{
	NUM_ROWS = num_rows;
	NUM_COLUMNS = num_columns;
	voidBox = void_box;
	playerSymbol = player_symbol;
	coinSymbol = coin_siymbol;
}
void Map::deafultMap()
{
	std::cout << "Numero de filas: ";
	std::cin >> nRows;
	std::cout << "Numero de columnas: ";
	std::cin >> nColumns;

	//Reservamos el espacio para el mapa
	punteroMapa = new char *[nRows]; //es necesario el puntero por que el numero de filas apunta al numero de columnas de cada fila
	for (int i = 0; i < nRows; i++) {
		punteroMapa[i] = new char[nColumns]; //aqui reservamos espacio para las columnas
	}

	std::cout << "\nGenerando mapa... ";
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nColumns; j++) {

			*(*(punteroMapa + i) + j) = '.';
			std::cout << *(*(punteroMapa + i) + j);
		}
	}
}


void main()
{
	Map deafultMap();

	deafultMap();
}