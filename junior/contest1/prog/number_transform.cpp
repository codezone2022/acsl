#include <bits/stdc++.h>
using namespace std;

// Units digit of a number is the digit in the one's place of the number.

int main() {
	for(long n = 0; n < 5; ++n) {
		long N, P, D; // [1..10^15]
		cin >> N >> P >> D;
		string ns = to_string(N);
		reverse(ns.begin(), ns.end()); // reverse for future convenience
		long pth = ns[P-1] - '0';
		if(0 <= pth && pth <= 4) { // [0..4]
			pth += D;
			ns[P-1] = pth % 10 + '0'; // replace pth digit with sum's unit digit
			for(long i = 0; i < P-1; ++i) // replace pth's right with all '0's
				ns[i] = '0';
		} else { // [5..9]
			pth -= D;
			pth = abs(pth);
			ns[P-1] = to_string(pth)[0];
		}
		for(long i = 0; i < P-1; ++i) // replace pth's right with all '0's
			ns[i] = '0';
		reverse(ns.begin(), ns.end()); // reverse back to normal
		cout << ns << endl;
	}
	return 0;
}
