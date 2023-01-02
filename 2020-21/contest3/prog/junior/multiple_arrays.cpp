#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	for(int n = 0; n < 5; ++n) {
		vector<long> ma[3];
		for(int i = 0; i < 3; ++i) {
			string line;
			getline(cin, line);
			istringstream is(line);
			while(true) {
				string token;
				is >> token;
				if(token.empty())
					break;
				auto num = stol(token); // stoi()
				ma[i].push_back(num);
			}
		}
		long sum = 0;
		size_t max_size = max({ma[0].size(), ma[1].size(), ma[2].size()});
		for(int j = 0; j < max_size; ++j) {
			long max_num = INT_MIN;
			for(int i = 0; i < 3; ++i)
				if(j < ma[i].size())
					max_num = max(max_num, ma[i][j]);
			sum += max_num;
		}
		cout << sum << endl;
	}
	return 0;
}
