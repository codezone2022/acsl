#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

int main() {
	for(int n = 0; n < 5; ++n) {
		string line;
		getline(cin, line);
		replace(line.begin(),line.end(),',',' ');
		istringstream sin(line);
		int pts = 0;
		int cards[10] = {};
		sin >> pts;
		for(int i = 0; i < 10; ++i)
			sin >> cards[i];
		//
		// TO_DO: Complete your solution here...
		//
	}
	return 0;
}
