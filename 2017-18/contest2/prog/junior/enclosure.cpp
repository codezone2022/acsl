#include <bits/stdc++.h>
using namespace std;

int main() {
	for(int n = 0; n < 5; ++n) {
		string exp, line;
		getline(cin, line);
		for(char ch : line) // remove spaces
			if(ch != ' ')
				exp += ch;
		vector<int> res;
		auto leftpos = exp.find('(');
		auto rightpos = exp.find(')');
		bool foundleft = (leftpos != string::npos);
		if(foundleft) { // missing right
			for(int i = leftpos; i < exp.length(); ++i) {
				char c = exp[i];
				switch(c) {
				case '+':
				case '-':
				case '*':
				case '/':
					res.push_back(i+3);
					break;
				}
			}
		} else { // missing left
			for(int i = 0; i < rightpos; ++i) {
				char c = exp[i];
				switch(c) {
				case '+':
				case '-':
				case '*':
				case '/':
					res.push_back(i);
					break;
				}
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
