#include <bits/stdc++.h>
using namespace std;

// n is 1-base
long fib(long one, long two, long n) {
	n %= 20;
	if(n == 0)
		n = 20;
	if(n == 1)
		return one;
	if(n == 2)
		return two;
	long f2 = one; long f1 = two; long fn = f2 + f1;
	for(int i = 3; i <= n; ++i) {
		fn = f2 + f1;
		f2 = f1;
		f1 = fn;
	}
	return fn;
}

int main() {
	for(int n = 0; n < 5; ++n) {
		long a; cin >> a;
		long b; cin >> b;
		char key; cin >> key;
		string msg; getline(cin, msg);
		for(int i = 1, N = msg.length(); i < N; ++i) {
			char ch = msg[i];
			long f = fib(a, b, i);
			char en = 'a' + ((key - 'a') + f) % 26;
			long offset = (long)ch + 3 * (long)en;
			cout << offset;
			if(i < N-1)
				cout << ' ';
		}
		cout << endl;
	}
	return 0;
}
