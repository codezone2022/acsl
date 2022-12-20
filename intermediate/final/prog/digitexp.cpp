#include <iostream>
#include <string>
#include <vector>
using namespace std;

long operand(string s) {
	if(s.empty() || s[0] == '0')
		return INT_MIN;
	return stol(s);
}

int main(int argc, char* argv[]) {
	int M = argc > 1 ? atoi(argv[1]) : 10;
	for(int m = 0; m < M; ++m) {
		string digits;
		cin >> digits;
		const long N = digits.size();
		long res = 0;
		// 1-operator
		for(int n = 1; n < N && N-n > 0; ++n) {
			auto str1 = digits.substr(0,n);
			auto str2 = digits.substr(n);
			long num1 = operand(str1);
			long num2 = operand(str2);
			if(num1 != INT_MIN && num2 != INT_MIN) {
				//cout << num1 << ' ' << num2 << endl;
				if(num1 + num2 > 0) ++res; // ++res;
				if(num1 - num2 > 0) ++res; // num1 > num2
				if(num1 * num2 > 0) ++res; // ++res;
			}
		}
		// 2-operator
		for(int i = 1; i < N; ++i) {
			for(int j = 1; j < N && N-i-j > 0; ++j) {
				auto str1 = digits.substr(0,i);
				auto str2 = digits.substr(i,j);
				auto str3 = digits.substr(i+j);
				long num1 = operand(str1);
				long num2 = operand(str2);
				long num3 = operand(str3);
				if(num1 != INT_MIN && num2 != INT_MIN && num3 != INT_MIN) {
					//cout << num1 << ' ' << num2 << ' ' << num3 << endl;
					if(num1 + num2 - num3 > 0) ++res;
					if(num1 - num2 + num3 > 0) ++res;
					if(num1 + num2 * num3 > 0) ++res;
					if(num1 * num2 + num3 > 0) ++res;
					if(num1 - num2 * num3 > 0) ++res;
					if(num1 * num2 - num3 > 0) ++res;
				}
			}
		}
		// 3-operator
		for(int i = 1; i < N; ++i) {
			for(int j = 1; j < N; ++j) {
				for(int k = 1; k < N && N-i-j-k > 0; ++k) {
					auto str1 = digits.substr(0,i);
					auto str2 = digits.substr(i,j);
					auto str3 = digits.substr(i+j,k);
					auto str4 = digits.substr(i+j+k);
					long num1 = operand(str1);
					long num2 = operand(str2);
					long num3 = operand(str3);
					long num4 = operand(str4);
					if(num1 != INT_MIN && num2 != INT_MIN && num3 != INT_MIN && num4 != INT_MIN) {
						//cout << num1 << ' ' << num2 << ' ' << num3 << ' ' << num4 << endl;
						if(num1 + num2 - num3 * num4 > 0) ++res;
						if(num1 + num2 * num3 - num4 > 0) ++res;
						if(num1 * num2 - num3 + num4 > 0) ++res;
						if(num1 * num2 + num3 - num4 > 0) ++res;
						if(num1 - num2 + num3 * num4 > 0) ++res;
						if(num1 - num2 * num3 + num4 > 0) ++res;
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
