#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Create a Pascal Triangle in the lower triangle of an NxN matrix, e.g.
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// ...
void createPascalTriangle(vector<vector<int>>& grid, int N) {
	// Put your solution here...
}

int fib(int N) {
	// Put your solution here...
}

// Given a Fibonacci number, return its 0-base or 1-base sequence
// Notice: 1-base sequence is always <  the Fibonacci number
//         0-base sequence is always <= the Fibonacci number
// It is up to your choice which one to return. For example:
// 0-base Seq: 0 1 2 3 4 5  6  7  8 ...
// 1-base Seq: 1 2 3 4 5 6  7  8  9 ...
//        Fib: 1 1 2 3 5 8 13 15 17 ...
int rev_fib(int f) {
	// Put your solution here...
}

int main() {
	for(int i = 0; i < 5; ++i) {
		int fib;
		cin >> fib;
		int N = rev_fib(fib);
		vector<vector<int>> grid(N, vector<int>(N, 0));
		createPascalTriangle(grid, N);
		// Print the 2nd diagonal line from lower-left
		// TO DO: Put your solution below or you can write it in a function...
	}
	return 0;
}
