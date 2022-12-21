import java.io.*;
import java.util.*;

public class patience {
	public static void main(String[] args) {
		int N = args.length > 0 ? Integer.parseInt(args[0]) : 10;
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < N && input.hasNextLine(); ++n) {
			StringTokenizer line = new StringTokenizer(input.nextLine());
			ArrayList<String> cards = new ArrayList<String>();
			while(line.hasMoreTokens())
				cards.add(line.nextToken());
			//TreeMap<Character,Integer> values = new TreeMap<Character,Integer>(); // TreeMap works the same
			HashMap<Character,Integer> values = new HashMap<Character,Integer>();
			values.put( 'A', 1 );
			values.put( '2', 2 );
			values.put( '3', 3 );
			values.put( '4', 4 );
			values.put( '5', 5 );
			values.put( '6', 6 );
			values.put( '7', 7 );
			values.put( '8', 8 );
			values.put( '9', 9 );
			values.put( 'T', 10);
			values.put( 'J', 11);
			values.put( 'Q', 12);
			values.put( 'K', 13);
			ArrayList<ArrayList<String>> piles = new ArrayList<ArrayList<String>>();
			for(String card : cards) {
				if(piles.isEmpty()) {
					ArrayList<String> p = new ArrayList<String>();
					p.add(card);
					piles.add(p);
					continue;
				}
				boolean placed = false;
				for(ArrayList<String> pile : piles) {
					String top = pile.get(pile.size()-1);
					//cout << top << '(' << values[top[0]] << ')' << " vs " << card << '(' << values[card[0]] << ')' << endl;
					if((values.get(top.charAt(0)) > values.get(card.charAt(0)) ||
						(top.charAt(0) == 'A' && card.charAt(0) == 'K')) && top.charAt(1) != card.charAt(1)) {
						pile.add(card);
						placed = true;
						break;
					}
				}
				if(!placed) {
					ArrayList<String> p = new ArrayList<String>();
					p.add(card);
					piles.add(p);
				}
			}
			int maxSize = 0;
			for(ArrayList<String> pile : piles)
				maxSize = Math.max(maxSize, pile.size());
			int minSum = Integer.MAX_VALUE;
			for(ArrayList<String> pile : piles) {
				if(pile.size() == maxSize) {
					int sum = 0;
					for(String card : pile)
						sum += values.get(card.charAt(0));
					minSum = Math.min(minSum, sum);
				}
			}
			System.out.println(minSum);
		}
	}
}
