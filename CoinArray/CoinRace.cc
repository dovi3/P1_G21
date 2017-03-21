#include <iostream>
#include "CoinRace.hh"


//Constructor de la clase Map
Map::Map(int num_rows, int num_columns, char void_box, char player_symbol, char coin_siymbol) 
{
	NUM_ROWS = num_rows;
	NUM_COLUMNS = num_columns;
	voidBox = void_box;
	playerSymbol = player_symbol;
	coinSymbol = coin_siymbol;
}
void Map::deafultMap() {
	const int numRows{ 10 };
	int numColumns{ 10 };
	int arr[numRows][numColumns];

	for(int i = 0; i < NUM_ROWS)


}