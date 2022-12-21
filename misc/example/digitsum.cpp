#include <iostream>
#include <cmath>
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

int main() {

	long num1 = 123;
	long num2 = 123456789;

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
	return 0;
}
