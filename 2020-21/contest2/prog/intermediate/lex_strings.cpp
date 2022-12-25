#include <bits/stdc++.h>
using namespace std;

int main() {
	while(true) { // for batch process - do not do this in your hackerrank.com solutions
		string s; int m;
		cin >> s >> m;
		if(!cin)
			break;
		// slice string s into blocks and save to a descendant storage
		string block;
		// key: string length, val: strings with the same length - in descending order
		map<size_t,multiset<string>,greater<size_t>> store;
		for(char c : s) {
			if(!block.empty() && block.back() != c) {
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
		// compress the chained
		int len = 0;
		string res;
		for(char cur : add) { // compress
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
