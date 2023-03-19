#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool num(string& exp, int& cur, int& res);
bool sign(string& exp, int& cur, int& res);

bool num(string& exp, int& cur, int& res) {
	if(cur < 0 || cur >= exp.length())
		return false;
	auto ch = exp[cur];
	if('0' <= ch && ch <= '9') {
		res = ch - '0';
		++cur;
		return true;
	}
	return sign(exp, cur, res);
}

bool sign(string& exp, int& cur, int& res) {
	if(cur < 0 || cur >= exp.length())
		return false;
	auto ch = exp[cur];
	switch(ch) {
	case '+':
		{
			++cur;
			int left = 0, right = 0;
			if(num(exp, cur, left) && num(exp, cur, right)) {
				res = left + right;
				return true;
			}
		}
	case '-':
		{
			++cur;
			int left = 0, right = 0;
			if(num(exp, cur, left) && num(exp, cur, right)) {
				res = left - right;
				return true;
			}
		}
	case '*':
		{
			++cur;
			int left = 0, right = 0;
			if(num(exp, cur, left) && num(exp, cur, right)) {
				res = left * right;
				return true;
			}
		}
	case '@':
		{
			++cur;
			int left = 0, mid = 0, right = 0;
			if(num(exp, cur, left) && num(exp, cur, mid) && num(exp, cur, right)) {
				res = left > 0 ? mid : right;
				return true;
			}
		}
	}
	return num(exp, cur, res);
}

int main() {
	for(int n = 0; n < 5; ++n) {
		string line;
		getline(cin, line);
		istringstream is(line);
		string exp;
		while(is) {
			char token = '\0';
			is >> token;
			if(!token)
				break;
			exp += token;
		}
		int idx = 0;
		int res = 0;
		sign(exp, idx, res); // prefix always starts with a sign
		cout << res << endl;
	}
	return 0;
}
