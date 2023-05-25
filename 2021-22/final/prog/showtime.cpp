#include <bits/stdc++.h>
using namespace std;

// Example 11:05:10
//         hh mm ss
// b  1 ->        5
// w  1 ->  1  5  5
// r  2 ->  2      
// r  3 ->  3
// r  5 ->  5
//         11  5 10

void calc(char color, int square, int& hour, int& min, int& sec) {
	switch(color) {
	case 'r':
		hour += square;
		break;
	case 'g':
		min += square*5;
		break;
	case 'b':
		sec += square*5;
		break;
	case 'y':
		hour += square;
		min += square*5;
		break;
	case 'c':
		min += square*5;
		sec += square*5;
		break;
	case 'm':
		hour += square;
		sec += square*5;
		break;
	case 'w':
		hour += square;
		min += square*5;
		sec += square*5;
		break;
	}
}

int main() {
	while(true) {
		string line;
		cin >> line;
		if(!cin || line.empty())
			break; // No more input data - exit program
		replace(line.begin(),line.end(),':',' ');
		istringstream iss(line);
		int hh, mm, ss;
		iss >> hh >> mm >> ss;
		string colors("krgbycmw"); // Must include k for black!!!
		vector<string> res;
		for(char i : colors) {
			for(char j : colors) {
				for(char k : colors) {
					for(char l : colors) {
						for(char m : colors) {
							int hour = 0, min = 0, sec = 0;
							calc(i, 1, hour, min, sec);
							calc(j, 1, hour, min, sec);
							calc(k, 2, hour, min, sec);
							calc(l, 3, hour, min, sec);
							calc(m, 5, hour, min, sec);
							if(hour == hh && min == mm && sec == ss) {
								// Found a match
								string s;
								s += i; s += j; s += k; s += l; s += m;
								res.push_back(s);
							}
						}
					}
				}
			}
		}
		sort(res.begin(), res.end());
		for(int n = 0, N = res.size(); n < N; ++n) {
			cout << res[n];
			if(n != N-1)
				cout << ' ';
			else
				cout << endl;
		}
	}
	return 0;
}
