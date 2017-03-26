#include <iostream>
#include <time.h>
#include "player.hh"
#include "Map.hh" 
#include <stdlib.h>
#include "CoinManager.hh"
#include <Windows.h>


int difi, coins;


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

//PRUEBAS
void updateMap(HANDLE hConsole, Map mapita, player &p1, CoinManager &coin, int coins)
{


}


void main()
{	
	//Cabecera del juego
	std::cout << "		///////////////////		" << std::endl;
	std::cout << "		    COIN RACE		" << std::endl;
	std::cout << "		//////////////////		" << std::endl;

	srand(time(nullptr));
	int numColumns, numRows;
	int Player1PosX;
	int  Player1PosY;
	bool GameOver = true;
	srand(time(nullptr));


	dificultad(numColumns, numRows);

	// Generant joc 
	Map mapita = Map(numColumns, numRows);					//Reserva memoria dinamica y la llena de '.'
	player p1 = player(numRows, numColumns);				//Inicialitza l'objecte p1
	//PRUEBAS
	//CoinManager coin = CoinManager(numRows, numColumns);
															
	while (GameOver) {
		
		if (!GameOver) {
			std::cout << "Selecciona la dificultad:\n 1: Easy\n 2: Medium\n 3: Hard\n" << std::endl;
		}
		
		int x_old = p1.PlayerPosX;
		int y_old = p1.PlayerPosY;
		mapita.updateBox(p1.PlayerPosX, p1.PlayerPosY, '@');
		mapita.drawMap();
		bool pressed = false;
		while (!pressed)										//Este bucle lee los eventos de teclado, no se sale del bucle hasta que no se pulsa algunas de las teclas.
		p1.moviment(numColumns, numRows, pressed);
		mapita.updateBox(p1.PlayerPosX, p1.PlayerPosY, '@');	 // Coje la nueva posición del player"@" y lo posiciona en el mapa (array)
		mapita.updateBox(x_old, y_old, '.');					// Coje la antigua posición del player"@" y lo borra (pinta un '.')
		system("cls");
		//PRUEBAS
		/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		srand(time(NULL));
		coins = (rand() % difi * 30 + 1) + difi * 30;
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "Recoge las monedas" << std::endl;
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << coins;
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << " coins" << std::endl;
		getch();
		const tcoin *CoinData;
		int CoinAcum;
		//mapita.updateBox(hConsole, mapita, p1, coin, coins);
		coin.initCoin(numRows, numColumns, '$');*/
		//PRUEBAS

	}
	
	
	
	std::cout << "Fin Del Juego" << std::endl;
}


