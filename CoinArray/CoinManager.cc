#include "coinManager.hh"
#include <string>
#include <ctime>

CoinManager::CoinManager(const int& rows, const int& cols) {
	Rows = rows;
	Cols = cols;
	initCoin(Rows, Cols, '$');
}

void CoinManager::removeCoin(const int &x, const int &y) {
	int pos = -1;
	for (int i = 0; i < coinAcum && pos == -1; i++) {
		if (coin[i].x == x && coin[i].y == y) {
			pos = i;
		}
	}
	if (pos >= 0 && pos < coinAcum) {
		for (int i = pos; i < coinAcum - 1; i++) {
			coin[i] = coin[i + 1];
		}
		coinAcum--;
		if (coinAcum > 0) {
			coin = static_cast<tcoin*>(realloc(coin, coinAcum * sizeof(tcoin)));
		}
		else {
			// cuando el jugador consiga todas las monedas, se vuelven
			// a generar de nuevo
			initCoin(Rows, Cols, '$');
		}
	}
}

int CoinManager::getCoin(const tcoin **p) const{
	*p = coin;
	return coinAcum;
}

void CoinManager::initCoin(const int & rows, const int & cols, char) {
	// valor aleatorio entre un 3 y un 13% del tamaño total del mapa
	srand(time(NULL));
	coinAcum = (rand() % (rows*cols / 10)) + rows*cols*0.03;
	coin = static_cast<tcoin*>(malloc(coinAcum * sizeof(tcoin)));
	int randX, randY;
	bool loop;
	// Genera una cantidad aleatoria de monedas
	for (int i = 0; i < coinAcum; i++) {
		// Genera la posicion aleatoria de cada moneda
		do {
			loop = false;
			randX = rand() % rows;
			randY = rand() % cols;
			// comoprueba si la nueva posicion de la moneda
			//ya ha sido repetida anteriormente
			for (int j = 0; j < i && !loop; j++) {
				if (coin[j].x == randX && coin[j].y == randY) {
					loop = true;
				}
			}
			// si la posicion se repite vueleve a generar otra aleatoria 
			//hasta encontrar una posicion libre
		} while (loop);
		coin[i].x = randX;
		coin[i].y = randY;
	}
}