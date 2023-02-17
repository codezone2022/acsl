import java.io.*;
import java.util.*;

public class string_difference {
	public static boolean is_vowel(char c) {
		switch(c) {
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			return true;
		}
		return false;
	}

	public static String remove_double_consonants(String s) {
		StringBuilder res = new StringBuilder();
		for(int i = 0; i < s.length(); ++i) {
			char c = s.charAt(i);
			if(res.length() == 0) {
				res.append(c);
				continue;
			}
			char p = res.charAt(res.length()-1);
			if(!is_vowel(p) && !is_vowel(c) && p == c)
					continue; // ignore the current character if both are consonants
			res.append(c);
		}
		return res.toString();
	}

	public static String remove_vowel(String s) {
		StringBuilder res = new StringBuilder();
		for(int i = 0; i < s.length(); ++i) {
			char c = s.charAt(i);
			if(!is_vowel(c))
				res.append(c);
		}
		return res.toString();
	}

	public static String[] remove_like_LR(String s1, String s2) {
		StringBuilder r1 = new StringBuilder();
		StringBuilder r2 = new StringBuilder();
		int len = Math.min(s1.length(), s2.length());
		for(int i = 0; i < len; ++i) {
			if(s1.charAt(i) == s2.charAt(i))
				continue; // skip if same
			r1.append(s1.charAt(i));
			r2.append(s2.charAt(i));
		}
		if(len == s1.length())
			for(int i = len; i < s2.length(); ++i)
				r2.append(s2.charAt(i));
		if(len == s2.length())
			for(int i = len; i < s1.length(); ++i)
				r1.append(s1.charAt(i));
		return new String[] {r1.toString(),r2.toString()};
	}

	public static String[] remove_like_RL(String s1, String s2) {
		StringBuilder sb1 = new StringBuilder(s1);
		StringBuilder sb2 = new StringBuilder(s2);
		s1 = sb1.reverse().toString();
		s2 = sb2.reverse().toString();
		String[] res = remove_like_LR(s1, s2);
		StringBuilder r1 = new StringBuilder(res[0]);
		StringBuilder r2 = new StringBuilder(res[1]);
		s1 = r1.reverse().toString();
		s2 = r2.reverse().toString();
		return new String[]{s1,s2};
	}

	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) {
			String one = input.next();
			String two = input.next();
			input.nextLine();

			one = remove_double_consonants(one);
			two = remove_double_consonants(two);

			one = remove_vowel(one);
			two = remove_vowel(two);

			String[] lrs = remove_like_LR(one, two);
			one = lrs[0]; two = lrs[1];
			String[] rls = remove_like_RL(one, two);
			one = rls[0]; two = rls[1];

			if(one.length() == two.length()) {
				if(one.compareTo(two) < 0)
					System.out.println(one);
				else
					System.out.println(two);
			} else {
				if(one.length() < two.length())
					System.out.println(one);
				else
					System.out.println(two);
			}
		}
	}
}
