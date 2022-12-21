#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int grid[4][4];

void print(int grid[4][4]) {
	cout << "----" << endl;
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}

int main() {
	string line;
	getline(cin, line);
	replace(line.begin(),line.end(),',',' ');
	istringstream is(line);
	for(int i = 0; i < 4; ++i) {
		int num = 0;
		is >> num;
		for(int j = 0; j < 4; ++j) {
			grid[i][3-j] = num % 10;
			num /= 10;
		}
	}
	for(int n = 0; n < 5; ++n) {
		int arr[4][4];
		for(int i = 0; i < 4; ++i) {
			for(int j = 0; j < 4; ++j) {
				arr[i][j] = grid[i][j];
			}
		}
		getline(cin, line);
		replace(line.begin(),line.end(),',',' ');
		istringstream sin(line);
		int r; int c;
		sin >> r >> c;
		--r; --c; // adjust 1-base to 0-base
		for(int step = 0; step < 6; ++step) {
			int& loc = arr[r][c];
			switch(loc) {
			case 0: // E
				++c;
				if(c > 3) c = 0;
				break;
			case 1: // W
				--c;
				if(c < 0) c = 3;
				break;
			case 2: // N
				--r;
				if(r < 0) r = 3;
				break;
			case 3: // S
				++r;
				if(r > 3) r = 0;
				break;
			}
			++loc;
			if(loc > 3) loc = 0;
		}
		cout << r+1 << ", " << c+1 << endl;
	}
	return 0;
}
