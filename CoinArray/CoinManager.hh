
typedef struct coin {
	int x;
	int y;
} tcoin;

class CoinManager{
public:
	CoinManager(const int& rows, const int& cols);
	void removeCoin(const int &x, const int &y);
	int getCoin(const tcoin** p) const;
	void initCoin(const int & rows, const int & cols, char);
private:
	tcoin* coin;
	int coinAcum;
	int Rows, Cols;
};