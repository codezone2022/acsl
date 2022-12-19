#include <iostream>
#include <queue>
using namespace std;

int main() {
	for(int n = 0; n < 5; ++n) {
		int pts = 0;
		char comma;
		int cards[10] = {};
		cin >> pts;
		for(int i = 0; i < 10; ++i) {
			cin >> comma >> cards[i];
			//debug//cout << cards[i] << ' ';
		}
		//debug//cout << endl;

		int total = pts;

		queue<int> playerHand;
		playerHand.push(cards[0]); // first 3 cards dealt to player
		playerHand.push(cards[1]);
		playerHand.push(cards[2]);

		for(int i = 3; i < 10; ++i) { // rest of the 10 cards
			if(i & 1) { // player's turn
				int use = playerHand.front();
				playerHand.pop();
				switch(use) {
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
					total += use;
					break;
				}
				//debug//cout << "card=" << cards[i] << " player=" << total << endl;
				if(total > 99) {
					cout << total << ", dealer" << endl;
					break;
				}
				playerHand.push(cards[i]);
			} else { // dealer's turn
				int use = cards[i];
				switch(use) {
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
					total += use;
					break;
				}
				//debug//cout << "card=" << cards[i] << " dealer=" << total << endl;
				if(total > 99) {
					cout << total << ", player" << endl;
					break;
				}
			}
		}
	}
	return 0;
}
