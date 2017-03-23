class player 
{

private:
public:
	int PlayerPosX, PlayerPosY;
	int PlayerScore;

public:
	player(int, int, int); //constructor de la classe
	void PlayerInit(int numRows, int numColumns, int &Player_PosX, int &Player_PosY);
	void moviment();



};
