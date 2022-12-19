import java.io.*;
import java.util.*;

// Units digit of a number is the digit in the one's place of the number.

public class number_transform {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		for(long n = 0; n < 5; ++n) {
			long N = input.nextLong(); // [1..10^15]
			int P = input.nextInt();
			int D = input.nextInt();
			input.nextLine();
			String ns = Long.toString(N);
			StringBuilder sb = new StringBuilder(ns); // Java strings are immutable
			sb.reverse(); // reverse for index calculation convenience
			int pth = sb.charAt(P-1) - '0';
			if(0 <= pth && pth <= 4) { // [0..4]
				pth += D;
				char ch = '0';
				ch += (pth % 10);
				sb.setCharAt(P-1, ch); // replace pth digit with sum's unit digit
				for(int i = 0; i < P-1; ++i) // replace pth's right with all '0's
					sb.setCharAt(i, '0');
			} else { // [5..9]
				pth -= D;
				pth = Math.abs(pth);
				sb.setCharAt(P-1, Integer.toString(pth).charAt(0));
			}
			for(int i = 0; i < P-1; ++i) // replace pth's right with all '0's
				sb.setCharAt(i, '0');
			sb.reverse(); // reverse back to normal
			System.out.println(sb);
		}
	}
}
