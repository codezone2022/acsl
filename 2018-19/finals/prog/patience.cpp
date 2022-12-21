#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char* argv[]) {
	int N = argc > 1 ? atoi(argv[1]) : 10;
	for(int n = 0; n < N; ++n) {
		string line;
		getline(cin,line);
		istringstream is(line);
		vector<string> cards;
		while(is) {
			string card;
			is >> card;
			if(card.empty())
				break;
			cards.push_back(card);
		}
		map<char,int> values {
			{ 'A', 1 }, { '2', 2 }, { '3', 3 }, { '4', 4 }, { '5', 5 }, { '6', 6 }, { '7', 7 }, { '8', 8 }, { '9', 9 }, { 'T', 10 }, { 'J', 11 }, { 'Q', 12 }, { 'K', 13 } };
		vector<vector<string>> piles;
		for(auto card : cards) {
			if(piles.empty()) {
				vector<string> p;
				p.push_back(card);
				piles.push_back(p);
				continue;
			}
			bool placed = false;
			for(auto& pile : piles) {
				auto top = pile.back();
				//cout << top << '(' << values[top[0]] << ')' << " vs " << card << '(' << values[card[0]] << ')' << endl;
				if((values[top[0]] > values[card[0]] || (top[0] == 'A' && card[0] == 'K')) && top[1] != card[1]) {
					pile.push_back(card);
					placed = true;
					break;
				}
			}
			if(!placed) {
				vector<string> p;
				p.push_back(card);
				piles.push_back(p);
			}
		}
		size_t maxSize = 0;
		for(auto& pile : piles)
			maxSize = max(maxSize, pile.size());
		size_t minSum = INT_MAX;
		for(auto& pile : piles) {
			if(pile.size() == maxSize) {
				size_t sum = 0;
				for(auto card : pile)
					sum += values[card[0]];
				minSum = min(minSum, sum);
			}
		}
		cout << minSum << endl;
	}
	return 0;
}
