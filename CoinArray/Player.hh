#include <iostream>
#include <time.h>

using namespace std;

class player
{
private:
	//Atributos
	int PlayerPosX;
	int PlayerPosY;

	int PlayerScore;
	//METODOS

	void movimiento();
	void InitPlayer(int &PlayerPosX, int &PlayerPosY, char arr[][]);
	void PlayerUpdate();

public:

	player(); // Prototip de constructor




	player();
	~player();
};



player::player()
{
}

player::~player()
{
}
