#include <iostream>
using namespace std;

bool match_given(char left[3][3], char right[3][3]) {
	for(int r = 0; r < 3; ++r)
		for(int c = 0; c < 3; ++c)
			if(left[r][c] && right[r][c] && left[r][c] != right[r][c])
				return false;
	return true;
}

bool just_once(char g[3][3]) {
	for(int r = 0; r < 3; ++r)
		for(int c = 0; c < 3; ++c) {
			for(int i = 0; i < 3; ++i) // check row r
				if(i != c && g[r][i] == g[r][c])
					return false;
			for(int i = 0; i < 3; ++i) // check col c
				if(i != r && g[i][c] == g[r][c])
					return false;
		}
	return true;
}

void print(char g[3][3]) {
	for(int r = 0; r < 3; ++r)
		for(int c = 0; c < 3; ++c)
			cout << g[r][c];
	cout << endl;
}

bool solve(char grid[3][3]) {
	for(char c1 : {'A', 'B', 'C'})
	for(char c2 : {'A', 'B', 'C'})
	for(char c3 : {'A', 'B', 'C'})
	for(char c4 : {'A', 'B', 'C'})
	for(char c5 : {'A', 'B', 'C'})
	for(char c6 : {'A', 'B', 'C'})
	for(char c7 : {'A', 'B', 'C'})
	for(char c8 : {'A', 'B', 'C'})
	for(char c9 : {'A', 'B', 'C'}) {
		char g[3][3] = { {c1, c2, c3}, {c4, c5, c6}, {c7, c8, c9} };
		if(!match_given(g, grid))
			continue;
		if(!just_once(g))
			continue;
		// Found one solution
		for(int r = 0; r < 3; ++r)
			for(int c = 0; c < 3; ++c)
				grid[r][c] = g[r][c];
		return true;
	}
	return false;
}

int main() {
	for(int n = 0; n < 5; ++n) {
		char grid[3][3] = { {}, {}, {} };
		int N;
		cin >> N;
		for(int i = 0; i < N; ++i) {
			char comma; int p; char c;
			cin >> comma >> p >> comma >> c;
			--p;
			grid[p/3][p%3] = c;
		}
		if(solve(grid))
			print(grid);
		else
			cout << "Solution not found!" << endl;
	}
	return 0;
}
