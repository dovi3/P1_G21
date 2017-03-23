#include <iostream>
#include <stdlib.h>
#include "Map.hh"

//Constructor de la clase Map
Map::Map(int num_rows, int num_columns) 
{
	NUM_ROWS = num_rows;
	NUM_COLUMNS = num_columns;
	voidBox = '.';
	playerSymbol = '@';
	coinSymbol = '$';

	//Reservamos el espacio para el mapa
	punteroMapa = new char *[NUM_ROWS];				//es necesario el puntero por que el numero de filas apunta al numero de columnas de cada fila
	for (int i = 0; i < NUM_ROWS; i++) {
		punteroMapa[i] = new char[NUM_COLUMNS];		//aqui reservamos espacio para las columnas
	}
}




void Map::updateBox(int Row, int Column, char value) {


	*(*(punteroMapa + Row) + Column) = value;
}



void Map::drawMap(int RowToUpdate, int ColToUpdate, char ChToUpdate)
{
	std::cout << "\nGenerando mapa...\n";
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {

			*(*(punteroMapa + i) + j) = voidBox;
			
			updateBox(RowToUpdate, ColToUpdate, ChToUpdate);
			std::cout << *(*(punteroMapa + i) + j) << " ";
		}
		std::cout << "\n";
	}
}


//Este metodo sirve para liberar la memoria una vez acabado el programa
void Map::freeMemory() 
{
	for (int i = 0; i < NUM_ROWS; i++)
		delete[] punteroMapa[i];

	delete[] punteroMapa;

}


