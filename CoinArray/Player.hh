class player 
{

private:
public:
	int PlayerPosX, PlayerPosY;
	int PlayerScore;

public:
	player(int, int); //constructor de la classe
	
	void moviment(int nRows, int nColumns, bool& pressed);
};

