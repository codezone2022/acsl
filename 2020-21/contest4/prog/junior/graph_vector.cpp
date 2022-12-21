#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Use vector instead of C-style arry for matrix

// Pass-by-reference with specific dimensions: C = AB
void multiply_matrix(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C) {
	for(size_t m = 0; m < A.size(); ++m) { // A's row count
		for(size_t p = 0; p < A[m].size(); ++p) { // A's col count
			int sum = 0;
			for(size_t n = 0; n < B.size(); ++n) // B's row count
				sum += A[m][n] * B[n][p];
			C[m][p] = sum;
		}
	}
}

int main() {
	for(int n = 0; n < 5; ++n) {
		vector<vector<int>> ma(10,vector<int>(10,0)); // A matrix with all zeros
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
				vector<vector<int>> mc(10,vector<int>(10,0));
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
