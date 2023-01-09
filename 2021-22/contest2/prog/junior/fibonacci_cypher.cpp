#include <bits/stdc++.h>
using namespace std;

int unique_fib(int n) { // 0-base sequence
	int f0 = 1; int f1 = 2;
	if(n == 0) return f0;
	if(n == 1) return f1;
	int f2 = f1 + f0;
	for(int i = 2; i <= n; ++i) {
		f2 = f1 + f0;
		f0 = f1;
		f1 = f2;
	}
	return f2;
}

int main() {
	for(int n = 0; n < 5; ++n) {
		string line;
		getline(cin, line);
		char key = line[0];
		for(int i = 2; i < line.length(); ++i) {
			cout << int((key - 'a' + unique_fib(i-2)) % 26 + 'a' + line[i]);
			if(i < line.length()-1)
				cout << ' ';
			else
				cout << endl;
		}
	}
	return 0;
}
