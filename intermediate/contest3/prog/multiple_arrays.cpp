#include <bits/stdc++.h>
using namespace std;

int main() {
	while(true) {
		int N,M;
		cin >> N >> M;
		if(!cin)
			break;
		vector<vector<int>> arr[3];
		for(int k = 0; k < 3; ++k) {
			arr[k].resize(N);
			for(int i = 0; i < N; ++i) {
				arr[k][i].resize(M);
				for(int j = 0; j < M; ++j)
					cin >> arr[k][i][j];
			}
		}
		int res = 0;
		for(int i = 0, j = 0; i < N && j < M;) {
			res += min({arr[0][i][j], arr[1][i][j], arr[2][i][j]});
			if(i == N -1 || j == M - 1)
				break;
			int max_val = max({
				arr[0][i][j+1], arr[0][i+1][j],
				arr[1][i][j+1], arr[1][i+1][j],
				arr[2][i][j+1], arr[2][i+1][j]});
			if((int(max_val == arr[0][i][j+1])+int(max_val == arr[0][i+1][j])+
				int(max_val == arr[1][i][j+1])+int(max_val == arr[1][i+1][j])+
				int(max_val == arr[2][i][j+1])+int(max_val == arr[2][i+1][j]))>1) {
				++i;
				++j;
			} else if(
				max_val == arr[0][i][j+1] ||
				max_val == arr[1][i][j+1] ||
				max_val == arr[2][i][j+1]) {
				++j;
			} else {
				++i;
			}
		}
		cout << res << endl;
	}
	return 0;
}
