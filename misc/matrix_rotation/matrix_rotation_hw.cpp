#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void rotate_horizontal(vector<vector<int>>& matrix) {
}

void rotate_vertical(vector<vector<int>>& matrix) {
}

void rotate_1st_diagonal(vector<vector<int>>& matrix) {
	// Hint: Iterate only half of the matrix (upper or lower triangle)
}

void rotate_2nd_diagonal(vector<vector<int>>& matrix) {
	// Hint: Iterate only half of the matrix (upper or lower triangle)
}

void spin_90degree_clockwise(vector<vector<int>>& matrix) {
	// Hint: A simple solution is to use 2 of the 4 functions above!
}

void print(ostream& os, const vector<vector<int>>& matrix);

int main() {

	vector<vector<int>> m1 {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
	};
	cout << "Before rotate horizontally:" << endl;
	print(cout, m1);
	rotate_horizontal(m1);
	cout << "After  rotate horizontally:" << endl;
	print(cout, m1);

	vector<vector<int>> m2 {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
	};
	cout << "Before rotate vertically:" << endl;
	print(cout, m2);
	rotate_vertical(m2);
	cout << "After  rotate viertically:" << endl;
	print(cout, m2);

	vector<vector<int>> m3 {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
	};
	cout << "Before rotate diagonally:" << endl;
	print(cout, m3);
	rotate_1st_diagonal(m3);
	cout << "After  rotate diagonally:" << endl;
	print(cout, m3);

	vector<vector<int>> m4 {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
	};
	cout << "Before rotate 2nd diagonally:" << endl;
	print(cout, m4);
	rotate_2nd_diagonal(m4);
	cout << "After  rotate 2nd diagonally:" << endl;
	print(cout, m4);

	vector<vector<int>> m5 {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
	};
	cout << "Before spinning 90 degree clockwise:" << endl;
	print(cout, m5);
	spin_90degree_clockwise(m5);
	cout << "After  spinning 90 degree clockwise:" << endl;
	print(cout, m5);
	return 0;
}

// Print M x N matrices
void print(ostream& os, const vector<vector<int>>& matrix) {
	const int M = matrix.size();
	if(M == 0) {
		os << "[]" << endl;
		return;
	}
	const int N = matrix[0].size();
	for(int r = 0; r < M; ++r) {
		for(int c = 0; c < N; ++c) {
			os << setw(3) << matrix[r][c];
		}
		os << endl;
	}
}
