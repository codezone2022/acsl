import java.io.*;
import java.util.*;

public class fibonacci_cypher {
	public static int unique_fib(int n) { // 0-base sequence
		int f0 = 1; int f1 = 2;
		if(n == 0) return f0;
		if(n == 1) return f1;
		int f2 = f1 + f0;
		for(int i = 2; i <= n; ++i) {
			f2 = f1 + f0;
			f0 = f1;
			f1 = f2;
		}
		return f2;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) {
			String line = input.nextLine();
			char key = line.charAt(0);
			for(int i = 2; i < line.length(); ++i) {
				int val = (((key - 'a') + unique_fib(i-2)) % 26 + 'a' + line.charAt(i));
				System.out.print(val);
				if(i < line.length()-1)
					System.out.print(' ');
				else
					System.out.println();
			}
		}
	}
}
