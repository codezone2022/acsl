#include <bits/stdc++.h>
using namespace std;

int main() {
	for(int N = 0; N < 5; ++N) {
		string line;
		getline(cin, line);
		vector<pair<bool,int>> st; // true when the token is an operator
		for(char ch : line) {
			if(ch == ' ')
				continue;
			if(ch == '+' || ch == '-' || ch == '*' || ch == '@') {
				st.push_back({true,ch});
				continue;
			}
			st.push_back({false,ch-'0'});
			bool found = false;
			int n = st.size();
			do {
				found = false;
				n = st.size();
				if(n >= 3 && st[n-3].first && st[n-3].second != '@' && !st[n-2].first && !st[n-1].first) {
					// found: +/-/* operand operand
					int res = 0;
					switch(st[n-3].second) {
					case '+': res = st[n-2].second + st[n-1].second; break;
					case '-': res = st[n-2].second - st[n-1].second; break;
					case '*': res = st[n-2].second * st[n-1].second; break;
					}
					st.pop_back();
					st.pop_back();
					st.pop_back();
					st.push_back({false,res});
					found = true;
					n = st.size();
				}
				if(n >= 4 && st[n-4].first && st[n-4].second == '@' && !st[n-3].first && !st[n-2].first && !st[n-1].first) {
					// found: @ operand operand operand
					int res = st[n-3].second > 0 ? st[n-2].second : st[n-1].second;
					st.pop_back();
					st.pop_back();
					st.pop_back();
					st.pop_back();
					st.push_back({false,res});
					found = true;
					n = st.size();
				}
			} while(found && n >= 3); // continue evaluation for possible expressions
		}
		cout << st.back().second << endl;
	}
	return 0;
}
