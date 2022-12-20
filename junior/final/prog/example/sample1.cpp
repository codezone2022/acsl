#include <bits/stdc++.h>
using namespace std;

int main() {
	int R = 5;
	int C = 3;

	// Step#1:
	// Sizes: Height by Width
	//for(int h = 1; h <= R; ++h)
	//	for(int w = 1; w <= C; ++w)
	//		cout << r << 'x' << c << endl;

	// Step#2:
	// 1) How to move the upper-left corner cell of the subrect?
	// 2) How to avoid out-of-range problem?

	// Step#3:
	// This is the typical zig-zag (upper-left to lower-right) traversal
	//for(int r = 0; r < R; ++r)
	//	for(int c = 0; c < C; ++c)
	//		cout << r << ',' << c << endl;

	// Step#4: Combine the above findings!
	//for(int h = 1; h <= R; ++h) {
	//	for(int w = 1; w <= C; ++w) {
	//		cout << h << 'x' << w << ": ";
	//		for(int r = 0; r <= R - h; ++r) // <- ranges!
	//			for(int c = 0; c <= C - w; ++c)
	//				cout << r << ',' << c << " ";
	//		cout << endl;
	//	}
	//}

	// Step#5: Sums?
	//int sum = 0;
	//for(int i = r; i < r+h; ++i)
	//	for(int j = c; j < c+w; ++j)
	//		sum += rect[i][j]; // <-

	// Step#6: Combine #5 with the above code
	int rect[10][10];
	cin >> R >> C;
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			cin >> rect[i][j];

	for(int h = 1; h <= R; ++h) {
		for(int w = 1; w <= C; ++w) {
			cout << h << 'x' << w << ": ";
			for(int r = 0; r <= R - h; ++r) {
				for(int c = 0; c <= C - w; ++c) {
					int sum = 0;
					for(int i = r; i < r+h; ++i)
						for(int j = c; j < c+w; ++j)
							sum += rect[i][j]; // <-
					cout << '(' << r << ',' << c << ")=" << sum << ' ';
				}
			}
			cout << endl;
		}
	}
	return 0;
}

