#include <iostream>
#include <time.h>
#include "Player.hh"
#include "Map.hh" 
#include "CoinManager.hh"
#include <stdlib.h>
#include <ctime>


int difi;

int dificultad(int& numRows, int& numColumns) {		// Retorna per referència els n de columnes i files determinat en base a la dificultat escollida
	int nRows = 5;
	int nColumns = 5;



	while (difi != 1 && difi != 2 && difi != 3) {	 // no es surt d'aquest bucle fins que la dificultat escollida sigui la correcta


		std::cout << "Selecciona la dificultad:\n 1: Easy\n 2: Medium\n 3: Hard\n" << std::endl;

		std::cin >> difi;							// Guarda el valor introduit a la variable difi

		if (difi != 1 && difi != 2 && difi != 3) {  // Si el usuari ha introduit un nombre que no es ni 1 ni 2 ni 3, ha de tornar a introduir-lo.
			std::cout << "debes elegir un numero del 1 al 3!!" << std::endl;
		}

	}


	numRows = rand() % (nRows * difi) + (nRows * difi);		  // calcula els n de files determinat en base a la dificultat escollida
	numColumns = rand() % (nColumns * difi) + (nColumns * difi); // els n de columnes determinat en base a la dificultat escollida
	return difi;
}



void main()
{

	std::cout << "		///////////////////		" << std::endl;
	std::cout << "		    COIN RACE		" << std::endl;
	std::cout << "		//////////////////		" << std::endl;


	srand(time(nullptr));
	int numColumns, numRows;
	int Player1PosX;
	int  Player1PosY;
	bool GameOver = false;
	srand(time(nullptr));
	int counter;
	//respecte dificultat facil, un valor dins de l'interval [20, 45]
	clock_t t;
	t = clock();

	dificultad(numColumns, numRows);
	int victory = ((rand() % 46) + 21); *&difi;

	// Generant joc 

	Map mapita = Map(numColumns, numRows);									//Reserva memoria dinamica y la llena de '.'
	player p1 = player(numRows, numColumns);								//Inicialitza l'objecte p1
	CoinManager coins = CoinManager(numRows, numColumns);

	for (int i = 0; i < coins.numCoins; /*nada*/) {							// Aquest for generara el nombre exacte de Cons que volem aleatoriament al mapa sense repetir posicions


		if (mapita.punteroMapa[coins.X][coins.Y] == '.') {					// Si no hi ha cap coin a la posició, en posa un i incrementa i, sino, a la seguent iteració del for es generara una altra posició 
			mapita.updateBox(coins.X, coins.Y, '$');
			i++;
		}

		coins.X = rand() % numColumns;										// Genera posicions aleatories però sempre dins del array generat.
		coins.Y = rand() % numRows;
	}
	counter = coins.numCoins;

	while (!GameOver)
	{
		std::cout << "Selecciona la dificultad:                          SCORE: " << p1.PlayerScore << "/" << victory << "\n 1: Easy\n 2: Medium\n 3: Hard\n" << std::endl;
		int x_old = p1.PlayerPosX;
		int y_old = p1.PlayerPosY;
		mapita.updateBox(p1.PlayerPosX, p1.PlayerPosY, '@');				// Posicionames el player en el mapa
		mapita.drawMap();													// pintamos el mapa	
		bool pressed = false;


		if (counter == 0) {													 // Comprueva si ya no quedan mas monedas en el mapa ncoins == player score

			for (int i = 0; i < coins.numCoins; /*nada*/) {					// Aquest for generara el nombre exacte de Cons que volem aleatoriament al mapa sense repetir posicions


				if (mapita.punteroMapa[coins.X][coins.Y] == '.') {			// Si no hi ha cap coin a la posició, en posa un i incrementa i, sino, a la seguent iteració del for es generara una altra posició 

					mapita.updateBox(coins.X, coins.Y, '$');
					i++;
				}

				coins.X = rand() % numColumns;								 // Genera posicions aleatories però sempre dins del array generat.
				coins.Y = rand() % numRows;
				counter = coins.numCoins;

			}
		}

		while (!pressed) {													//Este bucle lee los eventos de teclado, no se sale del bucle hasta que no se pulsa algunas de las teclas.
			p1.moviment(numColumns, numRows, pressed);
			if (mapita.punteroMapa[p1.PlayerPosX][p1.PlayerPosY] == '$')    // Comprueva la posicion del player en el Mapa y si en ésta hay un coin, incrementa el Score y decrementa counter
			{
				p1.PlayerScore++;
				counter--;
			}
			mapita.updateBox(p1.PlayerPosX, p1.PlayerPosY, '@');			 // Coje la nueva posición del player"@" y lo posiciona en el mapa (array)
			mapita.updateBox(x_old, y_old, '.');							// Coje la antigua posición del player"@" y lo borra (pinta un '.')



		}

		system("cls");

		if (p1.PlayerScore == victory) {


			GameOver = true;
		}

	}

	std::cout << "Fin Del Juego" << std::endl;
	std::cout << "Has recogido " << p1.PlayerScore << " monedas en " << ((float)t)/CLOCKS_PER_SEC << " segundos" <<"\n" << std::endl;

	system("pause");

}

