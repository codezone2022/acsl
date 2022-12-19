#include <iostream>
using namespace std;

int main() {
	// 10^50 is too big for 'long long' so use a string to handle
	string line[5];
	for(int n = 0; n < 5; ++n)
		cin >> line[n];
	cout << line[0].size() << endl; // line#1
	int sum = 0;
	for(char c : line[1])
		sum += (c - '0');
	cout << sum << endl; // line#2
	sum = 0;
	for(int i = 0; i < line[2].length(); ++i,++i)
		sum += (line[2][i] - '0');
	cout << sum << endl; // line#3
	int cnt = 0;
	for(char c : line[3])
		if(c == '4')
			++cnt;
	cout << cnt << endl; // line#4
	int len = line[4].length();
	int mid = len / 2;
	if((len & 1) == 0)
		--mid; // even length needs to adjust 1-base to 0-base
	cout << line[4][mid] << endl; // line#5
	return 0;
}
