#include <bits/stdc++.h>
using namespace std;

long long str_to_int(string str, long long base) {
	reverse(str.begin(), str.end());
	long long res = 0;
	for(long long i = 0, N = str.length(); i < N; ++i) {
		res += ((str[i] - '0') * (long long)(pow(base, i)));
	}
	return res;
}

long long digit_sum(long long num, long long base) {
	long long res = 0;
	while(num) {
		long long d = num % base;
		res += d;
		num /= base;
	}
	return res;
}

int main() {
	for(long long k = 0; k < 5; ++k) {
		long long n,b;
		string s;
		cin >> n >> b >> s;
		long long num = str_to_int(s, b);
		long long sum = 0;
		for(long long i = 0; i < n; ++i) {
			long long ds = digit_sum(num+i, b);
			sum += ds;
		}
		cout << sum << endl;
	}
	return 0;
}
