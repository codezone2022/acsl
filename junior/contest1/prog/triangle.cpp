#include <bits/stdc++.h>
using namespace std;

long digital_root(long num) {
	long res = 0;
	while(num >= 10) {
		res += (num % 10);
		num /= 10;
		if(num < 10) {
			res += num;
			num = res;
			res = 0;
		}
	}
	return num;
}

// Simulate the numbers needed to construct the required triangle
int main() {
	for(long n = 0; n < 5; ++n) { // read 5 input cases
		long s,d,r;
		cin >> s >> d >> r;
		long sum;
		long num = s;
		for(long i = 0; i < r; ++i) {
			sum = 0; long j = 0;
			for(; j <= i; ++j) {
				num = digital_root(num);
				sum += num;
				num += d;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
