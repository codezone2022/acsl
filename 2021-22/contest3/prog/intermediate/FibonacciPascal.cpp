#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Create a Pascal Triangle in the lower triangle of an NxN matrix, e.g.
// 1 1 2 3 5 8
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 ... ...
void createPascalTriangle(vector<vector<int>>& grid, int N) {
	grid[0][0] = 1; // Root/Seed
	for(int row = 1; row < N; ++row)
		for(int col = 0; col < row + 1; ++col)
			if(col == 0)
				grid[row][col] = grid[row-1][col];
			else
				grid[row][col] = grid[row-1][col] + grid[row-1][col-1];
}

// n is 1-base sequence
int fib(int n) {
	int f1 = 1; if(n==1) return f1;
	int f2 = 1; if(n==2) return f2;
	int fn = f2 + f1;
	for(int i = 3; i <= n; ++i) {
		fn = f1 + f2;
		f1 = f2; f2 = fn;
	}
	return fn;
}

// find 1-base sequence for the given fibonacci number
int seq(int f) {
	int n = 1;
	while(fib(n) != f) ++n;
	return n;
}

int main() {
	for(int i = 0; i < 5; ++i) {
		int fib;
		cin >> fib;
		int N = seq(fib);
		vector<vector<int>> grid(N, vector<int>(N, 0));
		createPascalTriangle(grid, N);
		// Travese the 2nd diagonal line from lower-left
		int even = 0, odd =  0, max_num = -1;
		for(int n = 0; n < N; ++n) {
			int num = grid[N-1-n][n];
			if(num > 0) {
				if((num & 1) == 0)
					++even;
				else
					++odd;
				max_num = max(max_num, num);
			}
		}
		cout << odd << ' ' << even << ' ' << max_num << endl;
	}
	return 0;
}
