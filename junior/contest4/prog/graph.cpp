#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Pass-by-reference with specific dimensions: C = AB
void multiply_matrix(int (&A)[10][10], int (&B)[10][10], int (&C)[10][10]) {
	for(size_t m = 0; m < 10; ++m) {
		for(size_t p = 0; p < 10; ++p) {
			int sum = 0;
			for(size_t n = 0; n < 10; ++n)
				sum += A[m][n] * B[n][p];
			C[m][p] = sum;
		}
	}
}

int main() {
	for(int n = 0; n < 5; ++n) {
		int ma[10][10] = {};
		string line;
		getline(cin, line);
		istringstream is(line);
		int prop = 0;
		is >> prop;
		while(is) {
			string edge;
			is >> edge;
			if(edge.empty())
				break;
			ma[ edge[0] -'0' ][ edge[1] - '0' ] = 1;
		}
		switch(prop) {
		case 1:
			{
				int res = 0;
				for(int i = 1; i <= 9; ++i) {
					res += ma[i][i];
					for(int j = i+1; j <= 9; ++j) {
						res += int(ma[i][j] && ma[j][i]);
					}
				}
				cout << res << endl;
			}
			break;
		case 2:
			{
				int max_edges = 0;
				int max_sum = 0;
				for(int i = 1; i <= 9; ++i) {
					int edges = 0;
					int sum = 0;
					for(int j = 1; j <= 9; ++j) {
						edges += ma[i][j];
						if(ma[i][j])
							sum += ((i*10)+j);
					}
					if( edges > max_edges ) {
						max_edges = edges;
						max_sum = sum;
					}
				}
				cout << max_sum << endl;
			}
			break;
		case 3:
			{
				int mc[10][10] = {};
				multiply_matrix(ma, ma, mc);
				int res = 0;
				for(int i = 1; i <= 9; ++i) {
					for(int j = 1; j <= 9; ++j) {
						res += mc[i][j];
					}
				}
				cout << res << endl;
			}
			break;
		}
	}
	return 0;
}
