#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int main() {
	for(int n = 0; n < 5; ++n) {
		vector<vector<bool>> ma(N,vector<bool>(N,false));
		string line;
		getline(cin,line);
		istringstream sin(line);
		while(true) {
			string edge;
			sin >> edge;
			if(!sin)
				break;
			int from = edge[0] - '0'; int to = edge[1] - '0';
			ma[from][to] = true;
		}
		int sum = 0;
		for(int i = 1; i < N; ++i) {
			for(int j = 1; j < N; ++j) {
				if(i == j || !ma[i][j])
					continue;
				for(int k = 1; k < N; ++k) {
					if(i == k || j == k || !ma[j][k])
						continue;
					sum += (i * 100 + j * 10 + k);
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
