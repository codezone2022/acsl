#include <bits/stdc++.h>
using namespace std;

//
// Use repeating modulo and division
//
long digitsum(long n, long r = 10) {
	long sum = 0;
	while(n) {
		sum += (n % r);
		n /= r;
	}
	return sum;
}

long digitsum_recursive(long n, long r = 10) {
	return n ? n % r + digitsum_recursive(n / r) : 0;
}

long digital_root0(long n, long r = 10) {
	while(n >= r) n = digitsum(n, r); // by definition
	return n;
}

long digital_root1(long n, long r = 10) {
	while(n >= r) {
		long sum = 0;
		while(n) {
			sum += (n % r);
			n /= r;
		}
		n = sum;
	}
	return n;
}

long digital_root2(long n, long r = 10) {
	if(n == 0)
		return 0;
	long rem = n % (r-1);
	return rem == 0 ? r-1 : rem;
}

long digital_root(long n, long r = 10) {
	return n == 0 ? 0 : 1 + (n-1) % (r-1);
}

int main() {

	long num1 = 123;
	long num2 = 123456789;

	// Digit Sum

	cout << "Digit Sum of " << dec << num1 << " (10) is " << dec << digitsum(num1) << " (10)" << endl;
	cout << "Digit Sum of " << dec << num2 << " (10) is " << dec << digitsum(num2) << " (10)" << endl;
	cout << endl;

	cout << "Digit Sum (recursive) of " << num1 << " (10) is " << dec << digitsum_recursive(num1) << " (10)" << endl;
	cout << "Digit Sum (recursive) of " << num2 << " (10) is " << dec << digitsum_recursive(num2) << " (10)" << endl;
	cout << endl;

	cout << "Digit Sum of " << oct << num1 << " (8) is " << dec << digitsum(num1, 8) << " (10)" << endl;
	cout << "Digit Sum of " << oct << num2 << " (8) is " << dec << digitsum(num2, 8) << " (10)" << endl;
	cout << endl;

	cout << "Digit Sum of " << uppercase << hex << num1 << " (16) is " << dec << digitsum(num1, 16) << " (10)" << endl;
	cout << "Digit Sum of " << uppercase << hex << num2 << " (16) is " << dec << digitsum(num2, 16) << " (10)" << endl;
	cout << endl;

	// Digital Root

	cout << "Digital Root of " << dec << num1 << " (10) is " << dec << digital_root(num1) << " (10)" << endl;
	cout << "Digital Root of " << dec << num2 << " (10) is " << dec << digital_root(num2) << " (10)" << endl;
	cout << endl;

	cout << "Digital Root of " << oct << num1 << " (8) is " << dec << digital_root(num1, 8) << " (10)" << endl;
	cout << "Digital Root of " << oct << num2 << " (8) is " << dec << digital_root(num2, 8) << " (10)" << endl;
	cout << endl;

	cout << "Digital Root of " << uppercase << hex << num1 << " (16) is " << dec << digital_root(num1, 16) << " (10)" << endl;
	cout << "Digital Root of " << uppercase << hex << num2 << " (16) is " << dec << digital_root(num2, 16) << " (10)" << endl;
	cout << endl;
	return 0;
}
