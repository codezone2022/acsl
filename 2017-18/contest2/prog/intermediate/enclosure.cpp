#include <bits/stdc++.h>
using namespace std;

// Missing (: locations on the left of the first digit but the number has no ), starting from [ stopping by )
// Missing ): locations on the operators or ], starting from ( stopping by ] inclusive
// Missing [: locations on the left of ( or the first digit, starting from the begin of string stopping by ( inclusive
// Missing ]: locations on the operators or ) or end of string, starting from ) stopping by the end of string

int main() {
	for(int n = 0; n < 5; ++n) {
		string exp;
		getline(cin, exp);
		vector<int> res;
		if(exp.find('(') == string::npos) { // Missing (
			int beg = exp.find('['); int end = exp.find(')');
			char pre = '\0';
			for(int i = beg + 1; i < end; ++i) {
				char cur = exp[i];
				if(isdigit(cur) && !isdigit(pre) && exp[i+1] != ')' && exp[i+2] != ')')
					res.push_back(i+1); // Convert to 1-base
				pre = cur;
			}
		} else if(exp.find(')') == string::npos) { // Missing )
			int beg = exp.find('('); int end = exp.find(']');
			for(int i = beg + 1; i <= end; ++i) {
				char cur = exp[i];
				if(cur == ']' ||
					((cur == '+' || cur == '-' || cur == '*' || cur == '/') && exp[i-2] != '(' && exp[i-3] != '('))
					res.push_back(i+1); // Convert to 1-base
			}
		} else if(exp.find('[') == string::npos) { // Missing [
			int beg = 0; int end = exp.find('(');
			char pre = '\0';
			for(int i = beg; i <= end; ++i) {
				char cur = exp[i];
				if((isdigit(cur) && !isdigit(pre)) || cur == '(')
					res.push_back(i+1); // Convert to 1-base
				pre = cur;
			}
		} else if(exp.find(']') == string::npos) { // Missing ]
			int beg = exp.find(')'); int end = exp.length()-1;
			for(int i = beg; i <= end; ++i) {
				char cur = exp[i];
				//cout << "exp[" << i << "]=" << cur << endl;
				if(cur == ')' || i == end) {
					if(res.empty() || res.back() != i+2)
						res.push_back(i+2); // Convert to 1-base
				} else if(cur == '+' || cur == '-' || cur == '*' || cur == '/') {
					if(res.empty() || res.back() != i+1)
						res.push_back(i+1); // Convert to 1-base
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
