#include <bits/stdc++.h>
using namespace std;

long long str_to_int(string str, long long base) {
	long long res = 0;
	for(long long i = 0, N = str.length(); i < N; ++i) {
		res += ((str[N-i-1] - '0') * (long long)(pow(base, i)));
	}
	return res;
}

int main() {
	for(int k = 0; k < 5; ++k) {
		long long n,b;
		string s;
		cin >> n >> b >> s;
		auto num = str_to_int(s, b);
		string nums;
		int cnts[10] = {};
		for(int i = 0; i < n; ++i) {
			long long numi = num + i;
			while(numi) {
				long long d = numi % b;
				++cnts[d];
				numi /= b;
			}
		}
		cout << cnts[b-1] << endl;
	}
	return 0;
}
