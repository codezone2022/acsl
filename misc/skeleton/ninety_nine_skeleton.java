import java.io.*;
import java.util.*;

// TO_DO: either rename the file or the class to make it work...
public class ninety_nine {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) { // read 5 input cases
			String line = input.nextLine();
			line = line.replace(',',' ');
			StringTokenizer stk = new StringTokenizer(line);
			int points = Integer.parseInt(stk.nextToken());
			int[] cards = new int[10];
			for(int i = 0; i < 10; ++i)
				cards[i] = Integer.parseInt(stk.nextToken());
			//
			// TO_DO: complete your solution here...
			//
		}
	}
}
