#include <iostream>
#include <cmath>
using namespace std;

long digital_root(long n) {
	return n == 0 ? 0 : 1 + (n-1) % 9;
}

int main() {
	for(int n = 0; n < 5; ++n) {
		long s,d,r;
		cin >> s >> d >> r;
		long num = digital_root(s + (r * ( r + 1 ) / 2 - r - 1) * d);// Skip through the one before the last row
		long sum = 0;
		for(int i = 0; i < r; ++i) {
			num = digital_root(num+d);
			//cout << num << ' '; // debug
			sum += num;
		}
		//cout << endl; // debug
		cout << sum << endl;
	}
	return 0;
}
