class Map
{
	private://Atributos
		int NUM_ROWS{};
		int NUM_COLUMNS{};
		char voidBox{ '.' };
		char playerSymbol{ '@' };
		char coinSymbol{ '$' };
	public://Metodos
		Map(int, int, char, char, char);//Constructor de la clase
		void deafultMap();
		void updateBox();
		void drawMap();
};
