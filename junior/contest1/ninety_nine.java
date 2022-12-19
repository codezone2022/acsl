import java.io.*;
import java.util.*;

public class ninety_nine {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) { // read 5 input cases
			int total = input.nextInt();
			int[] cards = new int[10];
			for(int i = 0; i < 10; ++i)
				cards[i] = input.nextInt();
			input.nextLine();

			Queue<Integer> playerHand = new LinkedList<>();
			playerHand.add(cards[0]);
			playerHand.add(cards[1]);
			playerHand.add(cards[2]);

			for(int i = 3; i < 10; ++i) {
				if(i % 2 == 1) { // player's turn
					int card = playerHand.poll();
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
						System.out.println(total + ", dealer");
						break;
					}
					playerHand.add(cards[i]);
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
						System.out.println(total + ", player");
						break;
					}
				}
			}
		}
	}
}
