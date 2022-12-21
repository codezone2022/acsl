#include <bits/stdc++.h>
using namespace std;

int main() {
	for(int n = 0; n < 5; ++n) {
		string s; int m;
		cin >> s >> m;
		// slice string s into blocks and save to a descendant storage
		string block;
		map<size_t,multiset<string>,greater<size_t>> store;
		for(char c : s) {
			if(block.empty() || block.back() != c) {
				store[block.length()].insert(block);
				block.clear();
			}
			block += c;
		}
		store[block.length()].insert(block); // don't forget about the leftover
		// combine the blocks
		string add;
		for(auto item : store) {
			auto& strs = item.second;
			for(auto& str : strs) {
				add += str;
			}
		}
		//cout << add << " -> ";
		// compress the chained
		int len = 0;
		string res;
		for(char cur : add) { // compress length
			if(cur == res.back()) {
				++len;
				if(len <= m)
					res += cur;
			} else {
				len = 1;
				res += cur;
			}
		}
		cout << res << endl;
	}
	return 0;
}
