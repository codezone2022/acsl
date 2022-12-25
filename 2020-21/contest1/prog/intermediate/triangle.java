import java.io.*;
import java.util.*;

public class triangle {
	public static int digit_sum_octal(int num) {
		String str = Integer.toOctalString(num);
		int sum = 0;
		for(int i = 0; i < str.length(); ++i) {
			char ch = str.charAt(i);
			ch -= '0';
			sum += ch;
		}
		return sum;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(true) { // You don't have to do this on hackerrank.com!
			int s,d,r;
			try {
				String s1 = input.next();
				s = Integer.parseInt(s1, 8);
				String s2 = input.next();
				d = Integer.parseInt(s2, 8);
			} catch(Exception e) {
				break;
			}
			r = input.nextInt();
			input.nextLine();
			int res = 0;
			for(int i = 1; i < r; ++i) {
				for(int j = 0; j <= i; ++j) {
					s += d;
					if(i == r-1) { // last row
						res += digit_sum_octal(s);
					}
				}
			}
			System.out.println(res);
		}
	}
}
