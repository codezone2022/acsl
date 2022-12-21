#include <bits/stdc++.h>
using namespace std;

int digit_sum_octal(int num) {
	ostringstream os;
	os << oct << num;
	auto str = os.str();
	int sum = 0;
	for(char ch : str) {
		sum += (ch - '0');
	}
	return sum;
}

int main() {
	for(int n = 0; n < 5; ++n) { // You won't need this loop in hackrank.com!
		int s,d,r;
		cin >> oct >> s >> oct >> d >> dec >> r; // s and d are in octal
		int res = 0;
		for(int i = 1; i < r; ++i) {
			for(int j = 0; j <= i; ++j) {
				s += d;
				if(i == r-1) { // last row
					res += digit_sum_octal(s);
				}
			}
		}
		cout << dec << res << endl;
	}
	return 0;
}
