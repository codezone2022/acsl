#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) {
	int N = argc > 1 ? atoi(argv[1]) : 10;
	for(int n = 0; n < N; ++n) {
		string text;
		getline(cin, text);
		string line;
		for(char ch : text)
			if(isalnum(ch))
				line += ch;
		string sorted = line;
		sort(sorted.begin(),sorted.end());
		int len = line.size();
		int cnt = 0;
		for(int j = 0, h = 0, t = len-1; line != sorted; ++j) {
			if((j&1)==0) { // Swap smallest character not in position
				for(; h < len; ++h)
					if(line[h] != sorted[h]) {
						auto old = line;
						auto found = line.find(sorted[h], h);
						swap(line[h], line[found]);
						++cnt;
						break;
					}
			} else { // Swap largest character not in position
				for(; t >= 0; --t)
					if(line[t] != sorted[t]) {
						auto old = line;
						auto found = line.rfind(sorted[t], t);
						swap(line[t], line[found]);
						++cnt;
						break;
					}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
