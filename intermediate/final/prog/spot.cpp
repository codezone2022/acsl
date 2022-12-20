#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int seq(int r, int c, int N) { return r * N + c + 1; }

void place(vector<vector<char>>& grid, int n, char piece) {
	int N = grid.size();
	int row = (n-1)/N;
	int col = (n-1)%N;
	grid[row][col] = piece;
}

int find(vector<vector<char>>& grid, char piece) {
	int N = grid.size();
	for(int i = 0; i <= N-3; ++i)
		for(int j = 0; j <= N-3; ++j) {
			if(grid[i][j] == piece && grid[i][j+2] == piece && grid[i+1][j+1] == piece && grid[i+2][j+1] == piece)
				return seq(i,j,N)+seq(i,j+2,N)+seq(i+1,j+1,N)+seq(i+2,j+1,N);
			if( grid[i][j] == piece && grid[i+2][j] == piece && grid[i+1][j+1] == piece && grid[i+1][j+2] == piece)
				return seq(i,j,N)+seq(i+2,j,N)+seq(i+1,j+1,N)+seq(i+1,j+2,N);
			if( grid[i][j+2] == piece && grid[i+1][j] == piece && grid[i+1][j+1] == piece && grid[i+2][j+2] == piece)
				return seq(i,j+2,N)+seq(i+1,j,N)+seq(i+1,j+1,N)+seq(i+2,j+2,N);
			if( grid[i][j+1] == piece && grid[i+1][j+1] == piece && grid[i+2][j] == piece && grid[i+2][j+2] == piece)
				return seq(i,j+1,N)+seq(i+1,j+1,N)+seq(i+2,j,N)+seq(i+2,j+2,N);
		}
	return 0;
}

int main(int argc, char* argv[]) {
	int K = argc > 1 ? atoi(argv[1]) : 10;
	for(int k = 0; k < K; ++k) {
		string line;
		getline(cin, line);
		istringstream is(line);
		vector<int> nums;
		while(is) {
			int num;
			is >> num;
			if(!is)
				break;
			nums.push_back(num);
		}
		int N = nums[0];
		vector<vector<char>> grid(N, vector<char>(N, '\0'));
		int found = 0;
		for(int i = 1; i < nums.size(); ++i) {
			place(grid, nums[i], (i&1)?'C':'S');
			found = find(grid, (i&1)?'C':'S');
			if(found)
				break;
		}
		cout << found << endl;
	}
	return 0;
}
