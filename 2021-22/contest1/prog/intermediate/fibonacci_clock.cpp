#include <bits/stdc++.h>
using namespace std;

int main() {
	for(int n = 0; n < 5; ++n) { // This loop is not needed on hackerrank.com!
		char lower_one, upper_one, two, three, five;
		cin >> lower_one >> upper_one >> two >> three >> five;
		int hour = 0, min = 0;
		// red
		if(lower_one == 'R') hour += 1;
		if(upper_one == 'R') hour += 1;
		if(two == 'R') hour += 2;
		if(three == 'R') hour += 3;
		if(five == 'R') hour += 5;
		// green
		if(lower_one == 'G') min += 1;
		if(upper_one == 'G') min += 1;
		if(two == 'G') min += 2;
		if(three == 'G') min += 3;
		if(five == 'G') min += 5;
		// blue
		if(lower_one == 'B') hour += 1, min += 1;
		if(upper_one == 'B') hour += 1, min += 1;
		if(two == 'B') hour += 2, min += 2;
		if(three == 'B') hour += 3, min += 3;
		if(five == 'B') hour += 5, min += 5;
		min *= 5;
		if(min >= 60) hour += (min/60), min %= 60;
		if(hour > 11) hour %= 12;
		cout<< setw(2) << setfill('0') << hour << ':'
			<< setw(2) << setfill('0') << min << endl;
	}
	return 0;
}
