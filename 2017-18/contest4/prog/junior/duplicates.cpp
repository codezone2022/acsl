#include <iostream>
#include <sstream>
using namespace std;

// 0 1 2 3 4 ...
// 1 2 3 5 8 ...
int fib(int n) {
	if(n == 0)
		return 1;
	if(n == 1)
		return 2;
	return fib(n-1) + fib(n-2);
}

string convert(string s) {
	string res;
	for(char c : s)
		if(isupper(c))
			res += c;
		else if(islower(c))
			res += ((char)toupper(c));
	return res;
}

int main() {
	for(int n = 0; n < 5; ++n) {
		int N;
		cin >> N;
		string line;
		getline(cin, line);
		auto str = convert(line);
		if(str.length() < N) {
			cout << 0 << endl;
			continue;
		}
		string res;
		bool cnts[26] = {}; // Counting Array
		for(int i = 0; i < str.length(); ++i) {
			res += str[i];
			sort(res.begin(), res.end());
			cout << res << endl;// random example to display info.
			if(i+1 >= N)
				cnts[res[N-1] - 'A'] = true;
		}
		int cnt = 0;
		for(int i = 0; i < 26; ++i)
			if(cnts[i])
				++cnt;
		cout << cnt << endl;
	}
	return 0;
}
