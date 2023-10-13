import java.io.*;
import java.util.*;

public class binary_counting {

	public static String reverse(String s) {
		return new StringBuilder(s).reverse().toString();
	}

	public static String to_string(int num, int base, int width) {
		if(num == 0)
			return new String("0");
		String res = new String();
		int i = 0;
		while(num > 0 || width != Integer.MAX_VALUE) {
			int d = num % base;
			res += (char)(d + '0');
			num /= base;
			if(++i >= width)
				break;
		}
		return reverse(res);
	}

	public static String remove_left(String src, String sub) {
		int pos = src.indexOf(sub);
		if(pos < 0)
			return src;
		String res = new String();
		for(int i = 0; i < src.length(); ++i) {
			if(i < pos || i >= pos + sub.length())
				res += src.charAt(i);
		}
		return res;
	}

	public static String remove_right(String src, String sub) {
		int pos = src.lastIndexOf(sub);
		if(pos < 0)
			return src;
		String res = new String();
		for(int i = 0; i < src.length(); ++i) {
			if(i < pos || i >= pos + sub.length())
				res += src.charAt(i);
		}
		return res;
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
				String l = remove_left(bs, s);
				String r = remove_right(l, s);
				if(bs == r)
					break;
				bs = r;
			}
			System.out.println(i-1);
		}
	}

}
