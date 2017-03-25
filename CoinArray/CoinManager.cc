#include "Map.hh"
#include <iostream>
#include "player.hh"
#include "CoinManager.hh"

CoinManager::CoinManager(int nRows, int nColumns) {

	int min = (nRows*nColumns)*0.03;
	int max = (nRows*nColumns)*0.13;
	int interval = (max - min);

	int numCoins = (rand() % interval) + min;

	
	
	for (int i = 0; i <= numCoins; /*nada*/) {						// Aquest for generara el nombre exacte de Cons que volem aleatoriament al mapa sense repetir posicions

		int X = rand() % nColumns;
		int Y = rand() % nRows;

		//Hem de poder cridar al array de la classe mapa per poder accedir directament.

		if (punteroMapa[X][Y] != '.' && punteroMapa[X][Y] != '@') { //genera X i Y random a cada iteracion del for
	
		
		//Aquí s'ha de cridar la funció "UpdateBox" de la classe Map per anar posicionant els diferents coins. (CREO QUE EL OMAR SABE COMO HACERLO, PREGUNTASELO)	
//             |
//             |
//             V			
			updateBox(X, Y, '$');									//Si a la posicio X i Y generada no hi ha un coin ni el player, posa el coin i augmenta i. 	
			i++;
		}
	
	}

}