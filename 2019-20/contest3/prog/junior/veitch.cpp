#include <bits/stdc++.h>
using namespace std;

using pus = pair<unsigned,string>;
using vpus = vector<pus>;

// From C++ 14, you can use 'b11110000' as binary literals

vpus fours = {
	{ bitset<8>{"11110000"}.to_ulong(), "B" },
	{ bitset<8>{"00001111"}.to_ulong(),"~B" },
	{ bitset<8>{"11001100"}.to_ulong(), "A" },
	{ bitset<8>{"01100110"}.to_ulong(), "C" },
	{ bitset<8>{"00110011"}.to_ulong(),"~A" },
	{ bitset<8>{"10011001"}.to_ulong(),"~C" }, // end column
};

vpus twos = {
	{ bitset<8>{"11000000"}.to_ulong(),  "AB"},
	{ bitset<8>{"01100000"}.to_ulong(),  "BC"},
	{ bitset<8>{"00110000"}.to_ulong(), "~AB"},
	{ bitset<8>{"00001100"}.to_ulong(), "A~B"},
	{ bitset<8>{"00000110"}.to_ulong(), "~BC"},
	{ bitset<8>{"00000011"}.to_ulong(),"~A~B"},
	{ bitset<8>{"10001000"}.to_ulong(), "A~C"},
	{ bitset<8>{"01000100"}.to_ulong(),  "AC"},
	{ bitset<8>{"00100010"}.to_ulong(), "~AC"},
	{ bitset<8>{"00010001"}.to_ulong(),"~A~C"},
	{ bitset<8>{"10010000"}.to_ulong(), "B~C"}, // end column
	{ bitset<8>{"00001001"}.to_ulong(),"~B~C"}, // end column
};

vpus ones = {
	{ bitset<8>{"10000000"}.to_ulong(),  "AB~C"},
	{ bitset<8>{"01000000"}.to_ulong(),   "ABC"},
	{ bitset<8>{"00100000"}.to_ulong(),  "~ABC"},
	{ bitset<8>{"00010000"}.to_ulong(), "~AB~C"},
	{ bitset<8>{"00001000"}.to_ulong(), "A~B~C"},
	{ bitset<8>{"00000100"}.to_ulong(),  "A~BC"},
	{ bitset<8>{"00000010"}.to_ulong(), "~A~BC"},
	{ bitset<8>{"00000001"}.to_ulong(),"~A~B~C"},
};

bool contains(unsigned bits, unsigned target) {
	return ((bits ^ target) | target) == bits;
}

int main() {
	while(true) {
		unsigned bits = 0;
		cin >> hex >> bits;
		if(!cin || !bits)
			break;
		string res;
		for(auto& item : fours) {
			auto tgt = item.first;
			auto exp = item.second;
			if(contains(bits, tgt)) {
				if(!res.empty())
					res += " + ";
				res += exp;
				bits ^= tgt;
			}
		}
		for(auto& item : twos) {
			auto tgt = item.first;
			auto exp = item.second;
			if(contains(bits, tgt)) {
				if(!res.empty())
					res += " + ";
				res += exp;
				bits ^= tgt;
			}
		}
		for(auto& item : ones) {
			auto tgt = item.first;
			auto exp = item.second;
			if(contains(bits, tgt)) {
				if(!res.empty())
					res += " + ";
				res += exp;
				bits ^= tgt;
			}
		}
		cout << res << endl;
	}
	return 0;
}
