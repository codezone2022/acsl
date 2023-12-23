#include <bits/stdc++.h>
using namespace std;

int main() {
	for(int n = 0; n < 5; ++n) {
		string exp;
		getline(cin, exp);
		vector<int> res;
		if(exp.find(')') == string::npos) { // missing )
			int beg = exp.find('('); int end = exp.length();
			for(int i = beg + 1; i < end; ++i) {
				char c = exp[i];
				if(c == '+' || c == '-' || c == '*' || c == '/')
					res.push_back(i+3);
			}
		} else if(exp.find('(') == string::npos) { // missing (
			int beg = 0; int end = exp.find(')');
			for(int i = beg; i < end; ++i) {
				char c = exp[i];
				if(c == '+' || c == '-' || c == '*' || c == '/')
					res.push_back(i);
			}
		}
		for(int i = 0; i < res.size(); ++i) {
			cout << res[i];
			if(i < res.size()-1)
				cout << ", ";
		}
		cout << endl;
	}
	return 0;
}
