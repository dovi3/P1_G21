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
		Map(int, int, char, char, char);//Constructor de la clase
		void deafultMap();	
		void drawMap(int RowToUpdate, int ColToUpdate, char ChToUpdate);
		void updateBox(int Row, int Column, char value);		
		void freeMemory();
};
