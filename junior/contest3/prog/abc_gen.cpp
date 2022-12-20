#include <iostream>
using namespace std;

void print_grid(char g[3][3]) {
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j)
			cout << (g[i][j] ? g[i][j] : '_');
		cout << endl;
	}
}

bool same(char c1, char c2) {
	return c1 && c2 && (c1 == c2);
}

bool canPlace(char g[3][3], int r, int c) {
	return !same(g[r][0],g[r][1])
		&& !same(g[r][1],g[r][2])
		&& !same(g[r][0],g[r][2])
		&& !same(g[0][c],g[1][c])
		&& !same(g[1][c],g[2][c])
		&& !same(g[0][c],g[2][c]);
}

void print(char g[3][3]) {
	for(int i = 0; i < 9; ++i)
		cout << g[i/3][i%3];
	cout << endl;
}

bool backtrack(char g[3][3], int p) {
	if(p >= 9) {
		print(g);
		return true;
	}
	int r = p/3; int c = p%3;
	if(g[r][c])
		return backtrack(g, p+1);
	for(char e : {'A', 'B', 'C'}) {
		g[r][c] = e;
		if(canPlace(g, r, c)) {
			backtrack(g, p+1);
		}
		g[r][c] = 0; // Important to remove the piece that failed!
	}
	return false;
}

char grid[3][3];

int main() {
	backtrack(grid, 0);
	return 0;
}
