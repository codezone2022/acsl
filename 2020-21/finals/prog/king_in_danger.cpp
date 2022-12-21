#include <bits/stdc++.h>
using namespace std;

using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;

void print(vvc& board) {
	for(int i = 0; i < 8; ++i) {
		for(int j = 0; j < 8; ++j)
			if(board[i][j])
				cout << board[i][j] << ' ';
			else
				cout << "  ";
		cout << endl;
	}
}

bool mark(vvc& board, vvc& check, int r, int c) {
	if(!(0 <= r && r < 8 && 0 <= c && c < 8))
		return false;
	if(!board[r][c]) {
		check[r][c] = 'C';
		return true;
	}
	check[r][c] = 'C';
	return false;
}

void place(vvc& board, vvc& check, vc& pieces, vi& rows, vi& cols) {
	for(int i = 0, N = pieces.size(); i < N; ++i) {
		char p = pieces[i]; int r = rows[i]; int c = cols[i];
		board[r][c] = p;
	}
	for(int i = 0, N = pieces.size(); i < N; ++i) {
		char p = pieces[i]; int r = rows[i]; int c = cols[i];
		switch(p) {
		case 'Q':
			for(int j = r-1; j >= 0 && mark(board, check, j, c); --j); // north
			for(int j = r+1; j <  8 && mark(board, check, j, c); ++j); // south
			for(int j = c-1; j >= 0 && mark(board, check, r, j); --j); // west
			for(int j = c+1; j <  8 && mark(board, check, r, j); ++j); // east
			for(int i = r-1, j = c-1; i >= 0 && j >= 0 && mark(board, check, i, j); --i, --j); // NW
			for(int i = r+1, j = c+1; i <  8 && j <  8 && mark(board, check, i, j); ++i, ++j); // SW
			for(int i = r-1, j = c+1; i >= 0 && j <  8 && mark(board, check, i, j); --i, ++j); // NE
			for(int i = r+1, j = c-1; i <  8 && j >= 0 && mark(board, check, i, j); ++i, --j); // SE
			break;
		case 'R':
			for(int j = r-1; j >= 0 && mark(board, check, j, c); --j); // north
			for(int j = r+1; j <  8 && mark(board, check, j, c); ++j); // south
			for(int j = c-1; j >= 0 && mark(board, check, r, j); --j); // west
			for(int j = c+1; j <  8 && mark(board, check, r, j); ++j); // east
			break;
		case 'B':
			for(int i = r-1, j = c-1; i >= 0 && j >= 0 && mark(board, check, i, j); --i, --j); // NW
			for(int i = r+1, j = c+1; i <  8 && j <  8 && mark(board, check, i, j); ++i, ++j); // SW
			for(int i = r-1, j = c+1; i >= 0 && j <  8 && mark(board, check, i, j); --i, ++j); // NE
			for(int i = r+1, j = c-1; i <  8 && j >= 0 && mark(board, check, i, j); ++i, --j); // SE
			break;
		case 'P':
			mark(board, check, r-1, c-1); // NW
			mark(board, check, r-1, c+1); // NE
			break;
		case 'N': // 8 directions of 'L'
			mark(board, check, r-2, c-1);
			mark(board, check, r-2, c+1);
			mark(board, check, r-1, c-2);
			mark(board, check, r-1, c+2);
			mark(board, check, r+1, c-2);
			mark(board, check, r+1, c+2);
			mark(board, check, r+2, c-1);
			mark(board, check, r+2, c+1);
			break;
		}
	}
}

bool in_check(vvc& check, int row, int col) {
	return check[row][col] == 'C';
}

bool has_a_move(vvc& check, int r, int c) {
	bool found = false;
	if(1 <= r && !in_check(check, r-1, c))
		found = true;
	if(r <  7 && !in_check(check, r+1, c))
		found = true;
	if(1 <= c && !in_check(check, r, c-1))
		found = true;
	if(c <  7 && !in_check(check, r, c+1))
		found = true;
	if(1 <= r && 1 <= c && !in_check(check, r-1, c-1))
		found = true;
	if(1 <= r && c <  7 && !in_check(check, r-1, c+1))
		found = true;
	if(r <  7 && 1 <= c && !in_check(check, r+1, c-1))
		found = true;
	if(r <  7 && c <  7 && !in_check(check, r+1, c+1))
		found = true;
	return found;
}

int main() {
	while(true) {
		string line;
		getline(cin, line);
		if(line.empty())
			break; // done with test cases
		vc pieces;
		vi cols;
		vi rows;
		int krow, kcol;
		istringstream sin(line);
		while(true) {
			string word;
			sin >> word;
			if(word.empty())
				break; // done with locations
			char p = word[0]; int col = word[1]-'a'; int row = '8'-word[2];
			pieces.push_back(p);
			cols.push_back(col);
			rows.push_back(row);
			if(p == 'K') {
				kcol = col;
				krow = row; 
			}
		}
		vvc board(8, vc(8, '\0'));
		vvc check = board;
		place(board, check, pieces, rows, cols);
		//print(board); cout << "----------------" << endl; print(check); cout << "----------------" << endl;
		if(in_check(check, krow, kcol)) {
			if(has_a_move(check,krow,kcol))
				cout << "CHECK" << endl;
			else
				cout << "CHECKMATE" << endl;
		} else {
			if(has_a_move(check,krow,kcol))
				cout << "SAFE" << endl;
			else
				cout << "STALEMATE" << endl;
		}
	}
	return 0;
}
