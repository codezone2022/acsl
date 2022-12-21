#include <bits/stdc++.h>
using namespace std;

int main() {
	for(int n = 0; n < 5; ++n) {
		int total = 0;
		int cards[10] = {};
		cin >> total;
		for(int i = 0; i < 10; ++i)
			cin >> cards[i];

		queue<int> playerHand;
		playerHand.push(cards[0]); // first 3 cards dealt to player
		playerHand.push(cards[1]);
		playerHand.push(cards[2]);

		for(int i = 3; i < 10; ++i) { // deal the rest of the 10 cards
			if(i & 1) { // player's turn
				int card = playerHand.front();
				playerHand.pop();
				switch(card) {
				case 9:
					break; // pass
				case 4:
					total -= 10;
					break;
				case 0:
					if(total + 11 <= 99)
						total += 11;
					else
						total += 1;
					break;
				default:
					total += card;
					break;
				}
				if(total > 99) {
					cout << total << ", dealer" << endl;
					break;
				}
				playerHand.push(cards[i]);
			} else { // dealer's turn
				int card = cards[i];
				switch(card) {
				case 9:
					break; // pass
				case 4:
					total -= 10;
					break;
				case 0:
					if(total + 11 <= 99)
						total += 11;
					else
						total += 1;
					break;
				default:
					total += card;
					break;
				}
				if(total > 99) {
					cout << total << ", player" << endl;
					break;
				}
			}
		}
	}
	return 0;
}
