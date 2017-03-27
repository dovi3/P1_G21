#include "Map.hh"
#include <iostream>
#include "player.hh"
#include "CoinManager.hh"

CoinManager::CoinManager(int nRows, int nColumns) {

	int min = (nRows*nColumns)*0.03;
	int max = (nRows*nColumns)*0.13;
	int interval = (max - min);

	numCoins = (rand() % interval) + min;

	X = rand() % nColumns;
	Y = rand() % nRows;
}


