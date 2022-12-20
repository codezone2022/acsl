import java.io.*;
import java.util.*;

public class string_stats {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		String s = input.nextLine();
		StringBuilder sb = new StringBuilder(s); // the mutable copy
		int[] diffs = new int[26]; // case insensitive counting array
		int vowels = 0;
		int up = 0;
		for(int i = 0; i < s.length(); ++i) {
			char c = s.charAt(i);
			if(Character.isUpperCase(c)) {
				++diffs[c-'A'];
				switch(c) {
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
					++vowels;
					break;
				}
				++up;
			} else if(Character.isLowerCase(c)) {
				++diffs[c-'a'];
				switch(c) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					++vowels;
					break;
				}
			} else { // non-letter
				sb.setCharAt(i, ' '); // replace with a space
			}
		}
		int cnt = 0; int max_val = 0;
		for(int i = 0; i < 26; ++i) {
			if(diffs[i] != 0)
				++cnt;
			max_val = Math.max(max_val, diffs[i]);
		}
		System.out.println(cnt);
		System.out.println(vowels);
		System.out.println(up);
		System.out.println(max_val);

		ArrayList<String> words = new ArrayList<String>();
		Scanner is = new Scanner(sb.toString());
		do {
			String word = is.next();
			if(word.isEmpty())
				break;
			if(words.isEmpty()) {
				words.add(word);
				continue;
			}
			if(word.length() < words.get(words.size()-1).length())
				continue; // skip shorter word
			if(word.length() == words.get(words.size()-1).length()) {
				words.add(word);
				continue; // add same length word
			}
			words.clear(); // empty storage for new longer length
			words.add(word);
		} while(is.hasNext());

		if(words.size() == 1) {
			System.out.println(words.get(0));
			return;
		}

		ArrayList<String> orgs = new ArrayList<String>(words);
		for(int i = 0; i < words.size(); ++i)
			words.get(i).toLowerCase(); // Convert to lower case for sorting
		Collections.sort(words);
		String first = words.get(0);
		for(int i = 0; i < words.size(); ++i)
			if(words.get(i).compareTo(first) == 0) {
				System.out.println(orgs.get(i)); // Output the one before conversion
				return;
			}
	}//end of main()
}//end of class
