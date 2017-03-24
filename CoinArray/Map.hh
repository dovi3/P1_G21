class Map
{
	private://Atributos
		
		char voidBox;
		char playerSymbol;
		char coinSymbol;
	public:
		char **punteroMapa;
		int NUM_ROWS;
		int NUM_COLUMNS;

	public://Metodos
		Map(int, int);													//Constructor de la clase
		void drawMap();
		void updateBox(int Row, int Column, char value);		
		void freeMemory();
};
