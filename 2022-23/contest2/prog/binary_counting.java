import java.io.*;
import java.util.*;

public class binary_counting {

	public static String to_string(int num, int base, int width) {
		String res = new String();
		int i = 0;
		while(num > 0 || width != Integer.MAX_VALUE) {
			int d = num % base;
			res += (char)(d + '0');
			num /= base;
			if(++i >= width)
				break;
		}
		return new StringBuilder(res).reverse().toString();
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for(int k = 0; k < 5; ++k) {
			String line = input.nextLine();
			String bs = new String();
			for(int i = 0; i < line.length(); ++i) {
				char ch = line.charAt(i);
				String cs = to_string((int)ch, 2, 8);
				bs += cs;
			}
			int i = 0;
			for(;;++i) {
				String s = to_string(i, 2, Integer.MAX_VALUE);
				if(!bs.contains(s))
					break;
			}
			System.out.println(i-1);
		}
	}

}
