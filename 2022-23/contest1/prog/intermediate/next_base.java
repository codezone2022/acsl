import java.io.*;
import java.util.*;
import java.lang.Math;

public class next_base {

	public static long str_to_int(String str, long base) {
		long res = 0;
		for(int i = 0, N =  str.length(); i < N; ++i) {
			res += ((str.charAt(N-i-1) - '0') * (long)(Math.pow(base, i)));
		}
		return res;
	}

	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		for(long k = 0; k < 5; ++k) {
			long n = input.nextLong();
			int b = input.nextInt();
			String s = input.next();
			input.nextLine();
			long num = str_to_int(s, b);
			int[] cnts = new int[10];
			for(long i = 0; i < n; ++i) {
				long numi = num + i;
				while(numi > 0) {
					int d = (int)(numi % b);
					++cnts[d];
					numi /= b;
				}
			}
			System.out.println(cnts[b-1]);
		}
	}
}
