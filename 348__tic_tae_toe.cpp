class tictaetoe{
private:
	vector<int> rows;
	vector<int> cols;
	int diag;
	int antidiag;
	int n;

public:
	tictaoetoe(int n): n(n),rows(n,0),cols(n,0),diag(0),antidiag(0)
	{}

	int move(int row, int col, int player){
		int score=(player==1)?1:-1;

		//update this score
		rows[row]+=score;
		cols[col]+=score;
		if(row==col){
			diag+=score;
		}
		if(row+col==n-1){
			antidiag+=score;
		}

		if(abs(rows[row])==n || abs(cols[col])==n || abs(diag)==n || abs(antidiag)==n){
			return player;
		}

		return 0;
	}
}
