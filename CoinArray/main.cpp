#include <iostream>
#include <time.h>
#include "Player.hh"
#include "Map.hh" 
#include "CoinManager.hh"
#include <stdlib.h>


int difi;



int dificultad(int& numRows, int& numColumns) {
	int nRows = 5;
	int nColumns = 5;

	difi = 0;
	while (difi != 1 && difi != 2 && difi != 3) {
	
	
		std::cout << "Selecciona la dificultad:\n 1: Easy\n 2: Medium\n 3: Hard\n" << std::endl;
		
		std::cin >> difi;

		if (difi != 1 && difi != 2 && difi != 3) {
			std::cout << "debes elegir un numero del 1 al 3!!" << std::endl;
		}
	
	}
	
	
	 numRows = rand() % (nRows * difi) + (nRows * difi);
	 numColumns = rand() % (nColumns * difi) + (nColumns * difi);
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


	dificultad(numColumns, numRows);

	// Generant joc 

	Map mapita = Map(numColumns, numRows);					//Reserva memoria dinamica y la llena de '.'
	player p1 = player(numRows, numColumns);				//Inicialitza l'objecte p1
	CoinManager coins = CoinManager(numRows, numColumns);

	for (int i = 0; i <= coins.numCoins; /*nada*/) {						// Aquest for generara el nombre exacte de Cons que volem aleatoriament al mapa sense repetir posicions


		if (mapita.punteroMapa[coins.X][coins.Y] == '.') {
			mapita.updateBox(coins.X, coins.Y, '$');
			i++;
		}

		coins.X = rand() % numColumns;
		coins.Y = rand() % numRows;
	}


	while (!GameOver) 
	{
		std::cout << "Selecciona la dificultad:                          SCORE: "  << p1.PlayerScore << "\n 1: Easy\n 2: Medium\n 3: Hard\n" << std::endl;
		int x_old = p1.PlayerPosX;
		int y_old = p1.PlayerPosY;
		mapita.updateBox(p1.PlayerPosX, p1.PlayerPosY, '@'); // Posicionames el player en el mapa
		mapita.drawMap();									// pintamos el mapa	
		bool pressed = false;
		
		
		
		while (!pressed) {											//Este bucle lee los eventos de teclado, no se sale del bucle hasta que no se pulsa algunas de las teclas.
			p1.moviment(numColumns, numRows, pressed);
			if (mapita.punteroMapa[p1.PlayerPosX][p1.PlayerPosY] == '$')   // Comprueva la posicion del player en el Mapa y si en �sta hay un coin, incrementa el Score
			{
				p1.PlayerScore++;
			}
			mapita.updateBox(p1.PlayerPosX, p1.PlayerPosY, '@');	 // Coje la nueva posici�n del player"@" y lo posiciona en el mapa (array)
			mapita.updateBox(x_old, y_old, '.');					// Coje la antigua posici�n del player"@" y lo borra (pinta un '.')		


			if (p1.PlayerScore >= coins.numCoins) {            // Comprueva la condicion de victoria ncoins == player score
				GameOver = true;
			}

		}
		
		system("cls");
		
		
	}
	std::cout << "Fin Del Juego" << std::endl;
}


