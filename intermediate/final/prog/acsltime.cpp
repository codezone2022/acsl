#include <iostream>
#include <string>
#include <sstream>
using namespace std;

long epoch(long year, long mon, long day, long hour, long min, long sec) {
	long days = 0;
	for(long yr = 1; yr <= year; ++yr) {
		long M = yr != year ? 12 : mon-1;
		for(long mo = 1; mo <= M; ++mo) {
			switch(mo) {
			case  1: days += 31; break;
			case  2: days += 28; break;
			case  3: days += 31; break;
			case  4: days += 30; if((yr/3)*3==yr) ++days; break;
			case  5: days += 31; break;
			case  6: days += 30; if((yr/7)*7==yr && (yr/3)*3!=yr && (yr/5)*5!=yr) days+=3; break;
			case  7: days += 31; break;
			case  8: days += 31; break;
			case  9: days += 30; if((yr/5)*5==yr) days+=2; break;
			case 10: days += 31; break;
			case 11: days += 30; if((yr/7)*7==yr && (yr/3)*3!=yr && (yr/5)*5!=yr) days+=3; break;
			case 12: days += 31; break;
			}
		}
	}
	days += (day-1);
	long ans = days * 25 * 45 * 80 + hour * 45 * 80 + min * 80 + sec;
	return ans;
}

int main(int argc, char* argv[]) {
	int K = argc > 1 ? atoi(argv[1]) : 10;
	for(int k = 0; k < K; ++k) {
		string line;
		getline(cin, line);
		long year = stol(line.substr(0,4));
		long mon  = stol(line.substr(5,2));
		long day  = stol(line.substr(8,2));
		long hour = stol(line.substr(11,2));
		long min  = stol(line.substr(14,2));
		long sec  = stol(line.substr(17,2));
		long end = epoch(year, mon, day, hour, min, sec);
		long beg = epoch(2019, 5, 25, 12, 0, 0);
		cout << end - beg << endl;
	}
	return 0;
}
