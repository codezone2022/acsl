import java.io.*;
import java.util.*;

// Can use BigInteger to allow even bigger numbers!!!

public class digitexp {

	public static long operand(String s) {
		if(s == null || s.isEmpty() || s.charAt(0) == '0')
			return Long.MIN_VALUE;
		return Long.parseLong(s);
	}

	public static void main(String[] args) {
		int M = args.length > 0 ? Integer.parseInt(args[0]) : 10;
		Scanner input = new Scanner(System.in);
		for(int m = 0; m < M && input.hasNextLine(); ++m) {
			String digits = input.nextLine();
			long N = digits.length();
			long res = 0;
			// 1-operator
			for(int n = 1; n < N && N-n > 0; ++n) {
				String str1 = digits.substring(0,n);
				String str2 = digits.substring(n);
				long num1 = operand(str1);
				long num2 = operand(str2);
				if(num1 != Long.MIN_VALUE && num2 != Long.MIN_VALUE) {
					//cout << num1 << ' ' << num2 << endl;
					if(num1 + num2 > 0) ++res;
					if(num1 - num2 > 0) ++res;
					if(num1 * num2 > 0) ++res;
				}
			}
			// 2-operator
			for(int i = 1; i < N; ++i) {
				for(int j = 1; j < N && N-i-j > 0; ++j) {
					String str1 = digits.substring(0,i);
					String str2 = digits.substring(i,i+j);
					String str3 = digits.substring(i+j);
					long num1 = operand(str1);
					long num2 = operand(str2);
					long num3 = operand(str3);
					if(num1 != Long.MIN_VALUE && num2 != Long.MIN_VALUE && num3 != Long.MIN_VALUE) {
						//cout << num1 << ' ' << num2 << ' ' << num3 << endl;
						if(num1 + num2 - num3 > 0) ++res;
						if(num1 - num2 + num3 > 0) ++res;
						if(num1 + num2 * num3 > 0) ++res;
						if(num1 * num2 + num3 > 0) ++res;
						if(num1 - num2 * num3 > 0) ++res;
						if(num1 * num2 - num3 > 0) ++res;
					}
				}
			}
			// 3-operator
			for(int i = 1; i < N; ++i) {
				for(int j = 1; j < N; ++j) {
					for(int k = 1; k < N && N-i-j-k > 0; ++k) {
						String str1 = digits.substring(0,i);
						String str2 = digits.substring(i,i+j);
						String str3 = digits.substring(i+j,i+j+k);
						String str4 = digits.substring(i+j+k);
						long num1 = operand(str1);
						long num2 = operand(str2);
						long num3 = operand(str3);
						long num4 = operand(str4);
						if(num1 != Long.MIN_VALUE && num2 != Long.MIN_VALUE && num3 != Long.MIN_VALUE && num4 != Long.MIN_VALUE) {
							//cout << num1 << ' ' << num2 << ' ' << num3 << ' ' << num4 << endl;
							if(num1 + num2 - num3 * num4 > 0) ++res;
							if(num1 + num2 * num3 - num4 > 0) ++res;
							if(num1 * num2 - num3 + num4 > 0) ++res;
							if(num1 * num2 + num3 - num4 > 0) ++res;
							if(num1 - num2 + num3 * num4 > 0) ++res;
							if(num1 - num2 * num3 + num4 > 0) ++res;
						}
					}
				}
			}
			System.out.println(res);
		}
	}
}
