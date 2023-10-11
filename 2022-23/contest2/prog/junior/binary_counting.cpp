#include <bits/stdc++.h>
using namespace std;

string to_string(int num, int base, int width = INT_MAX) {
	string res;
	int i = 0;
	while(num || width != INT_MAX) {
		int d = num % base;
		res += (d + '0');
		num /= base;
		if(++i >= width)
			break;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	for(int k = 0; k < 5; ++k) {
		string line;
		getline(cin, line);
		string bs;
		for(char ch : line) {
			auto cs = to_string(ch, 2, 8);
			bs += cs;
		}
		int i = 0;
		for(;;++i) {
			auto s = to_string(i, 2);
			if(bs.find(s) == string::npos)
				break;
		}
		cout << i - 1 << endl;
	}
	return 0;
}
