#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int N = 10;
	if(argc > 1) {
		N = atoi(argv[1]);
		if(N <= 0)
			N = 10;
	}
	for(int k = 0; k < N; ++k) {
		int arr[10][10];
		int m,n;
		cin >> m >> n;
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				cin >> arr[i][j];
		int max_sum = INT_MIN;
		// Complete Search each dxw rectangles
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				for(int d = 1; d <= m; ++d) {
					for(int w = 1; w <= n; ++w) {
						if(i+d <= m && j+w <= n) {
							int sum = 0;
							for(int r = i; r < i+d; ++r)
								for(int c = j; c < j+w; ++c)
									sum += arr[r][c];
							max_sum = max(max_sum, sum);
						}
					}
				}
			}
		}
		cout << max_sum << endl;
	}
	return 0;
}
