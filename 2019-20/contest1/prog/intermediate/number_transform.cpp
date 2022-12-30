#include <bits/stdc++.h>
using namespace std;

// |<--- left --->|P|<--- right --->|
// abcdefghijklmnopqrstuvwxyzabcdefgh    <- sample digits
// left: unit digit of the sum between that digit and the Pth digit
// Pth: unchanged
// right: absolute value of the difference between that digit and the Pth digit
// Notice: Pth is 1-base from the right

int main() {
	while(true) {
		string N;
		cin >> N;
		if(!cin || N.empty())
			break;
		int P;
		cin >> P;
		for(int i = 0; i < N.length(); ++i) {
			int idx = N.length() - P; // convert Pth from the right to 0-base index from the left
			if(i < idx) { // left
				N[i] = (((N[i] - '0') + (N[idx] - '0')) % 10 + '0');
			} else if(i > idx) { // right
				N[i] = (abs((N[i] - '0') - (N[idx] - '0')) + '0');
			}
		}
		cout << N << endl;
	}
	return 0;
}
