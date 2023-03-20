#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int num) {
	if(num < 2)
		return false;
	for(int n = 2, end = int(sqrt(num)); n <= end; ++n)
		if( (num / n) * n == num ) // divisible check
			return false;
	return true;
}

int& getMarker(vector<int>& players) {
	if(players[0] < players[1] && players[0] < players[2]) return players[0];
	if(players[1] < players[0] && players[1] < players[2]) return players[1];
	return players[2];
}

bool occupied(int curr, int next, vector<int>& players) {
	bool res = false;
	for(int player : players) {
		if(curr == player)
			continue; //skip self compare
		if(next == player)
			return true;
	}
	return false;
}

int main() {
	for(int n = 0; n < 5; ++n) {
		int opponent[3] = {};
		vector<int> player(3,0);
		int num_rolls = 0;
		cin >> opponent[0] >> opponent[1] >> opponent[2] >> player[0] >> player[1] >> player[2] >> num_rolls;
		vector<int> rolls(num_rolls, 0);
		for(int i = 0; i < num_rolls; ++i)
			cin >> rolls[i];
		for(int roll : rolls) {
			int& curr = getMarker(player);
			if(curr == 52)
				break;
			int next = curr + roll;
			//cout << "curr=" << curr << ",roll=" << roll << ",next=" << next << endl;
			// Check if will land on an occupied location
			if( next == opponent[0] || next == opponent[1] || next == opponent[2] || occupied(curr, next, player) )
				continue;
			// Check if will land on target location 52
			if( next == 52 ) {
				curr = next;
				continue;
			}
			// Check if will land beyond 52
			if( next > 52 )
				continue;
			// Check if will land on prime #
			if( isPrime(next) ) {
				for(int i = 0; i < 6; ++i) {
					++next;
					if( next == opponent[0] || next == opponent[1] || next == opponent[2] || occupied(curr, next, player) ) {
						--next;
						break;
					}
				}
				curr = next;
				continue;
			}
			// Check if will land on perfect square > 4
			if( next == 9 || next == 16 || next == 25 || next == 36 || next == 49 ) {
				for(int i = 0; i < 6; ++i) {
					--next;
					if( next == opponent[0] || next == opponent[1] || next == opponent[2] || occupied(curr, next, player) ) {
						++next;
						break;
					}
				}
				curr = next;
				continue;
			}
			// Check if one horizontal move followed by one vertical move
			if( (curr <  7 &&  7 < next) ||
				(curr < 12 && 12 < next) ||
				(curr < 17 && 17 < next) ||
				(curr < 22 && 22 < next) ||
				(curr < 27 && 27 < next) ||
				(curr < 35 && 35 < next) ||
				(curr < 40 && 40 < next) ||
				(curr < 45 && 45 < next) ||
				(curr < 50 && 50 < next) )
			{
				for(; next > curr; --next) {
					if( (next / roll) * roll == next && next != opponent[0] && next != opponent[1] && next != opponent[2] && !occupied(curr, next, player) )
						// Unoccupied multiple of roll
						break;
				}
				curr = next;
				continue;
			}
			curr = next;
		}
		sort(player.begin(),player.end());
		if(player[0] == 52 && player[1] == 52 && player[2] == 52)
			cout << "GAME OVER" << endl;
		else {
			for(int i : player)
				if(i == 52)
					break;
				else
					cout << i << ' ';
			cout << endl;
		}
	}
	return 0;
}
