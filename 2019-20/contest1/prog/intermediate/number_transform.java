import java.io.*;
import java.util.*;

// |<--- left --->|P|<--- right --->|
// abcdefghijklmnopqrstuvwxyzabcdefgh    <- sample digits
// left: unit digit of the sum between that digit and the Pth digit
// Pth: unchanged
// right: absolute value of the difference between that digit and the Pth digit
// Notice: Pth is 1-base from the right

public class number_transform {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(true) {
			String s;
			int P;
			try {
				s = input.next();
				P = input.nextInt();
				input.nextLine();
			} catch(Exception e) {
				break;
			}
			StringBuilder N = new StringBuilder(s);
			int idx = N.length() - P; // convert Pth from the right to 0-base index from the left
			for(int i = 0; i < N.length(); ++i) {
				char ith = N.charAt(i);
				char pth = N.charAt(idx);
				int ival = ith - '0';
				int pval = pth - '0';
				if(i < idx) { // left
					int d = (ival + pval) % 10;
					char c = '0'; c += d;
					N.setCharAt(i, c);
				} else if(i > idx) { // right
					int d = Math.abs(ival - pval);
					char c = '0'; c += d;
					N.setCharAt(i, c);
				}
			}
			System.out.println(N);
		}
	}
}
