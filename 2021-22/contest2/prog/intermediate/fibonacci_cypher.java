import java.io.*;
import java.lang.*;
import java.util.*;

public class solution {
	// n is 1-base
	public static int fib(int one, int two, int n) {
		n %= 20;
		if(n == 0)
			n = 20;
		if(n == 1)
			return one;
		if(n == 2)
			return two;
		int f2 = one; int f1 = two; int fn = f2 + f1;
		for(int i = 3; i <= n; ++i) {
			fn = f2 + f1;
			f2 = f1;
			f1 = fn;
		}
		return fn;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) {
			int a = input.nextInt();
			int b = input.nextInt();
			char key = input.next().charAt(0);
			String msg = input.nextLine();
			for(int i = 1, N = msg.length(); i < N; ++i) {
				char ch = msg.charAt(i);
				int f = fib(a, b, i);
				int en = (int)'a' + (((int)key - (int)'a') + f) % 26;
				int offset = (int)ch + 3 * en;
				System.out.print(offset);
				if(i < N-1)
					System.out.print(' ');
			}
			System.out.println();
		}
	}
}
