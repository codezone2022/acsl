#include <bits/stdc++.h>
using namespace std;

string to_string(int num, int base, int width = INT_MAX) {
	if(!num)
		return "0";
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

// remove b from a on the left
string remove_left(string a, string b) {
	auto pos = a.find(b);
	if(pos == string::npos)
		return a; // not found
	string l = a.substr(0, pos);
	string r = a.substr(pos + b.length(), a.length() - pos - b.length());
	return l + r;
}

// remove b from a on the right
string remove_right(string a, string b) {
	auto pos = a.rfind(b);
	if(pos == string::npos)
		return a;
	string l = a.substr(0, pos);
	string r = a.substr(pos + b.length(), a.length() - pos - b.length());
	return l + r;
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
			auto l = remove_left(bs, s);
			auto r = remove_right(l, s);
			if(bs == r)
				break;
			bs = r;
		}
		cout << i - 1 << endl;
	}
	return 0;
}
