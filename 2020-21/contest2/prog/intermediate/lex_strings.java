import java.io.*;
import java.util.*;

public class lex_strings {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(true) { // for batch process - do not do this in your hackerrank.com solutions
			String s; int m;
			try {
				s = input.next();
				m = input.nextInt();
			} catch(Exception e) {
				break; // exit the program
			}
			// slice string s into blocks and save to a descendant storage
			StringBuilder block = new StringBuilder();
			// key: string length, val: strings with the same length - in descending order
			TreeMap<Integer,ArrayList<String>> store =
				new TreeMap<Integer,ArrayList<String>>(Collections.reverseOrder());
			for(int i = 0; i < s.length(); ++i) {
				char c = s.charAt(i);
				if(block.length()>0 && block.charAt(block.length()-1) != c) {
					ArrayList<String> arr;
					if(store.get(block.length())==null) {
						arr = new ArrayList<String>();
						store.put(block.length(), arr);
					} else {
						arr = store.get(block.length());
					}
					arr.add(block.toString());
					block = new StringBuilder();
				}
				block.append(c);
			}
			// don't forget about the leftover
			ArrayList<String> arr;
			if(store.get(block.length())==null) {
				arr = new ArrayList<String>();
				store.put(block.length(), arr);
			} else {
				arr = store.get(block.length());
			}
			arr.add(block.toString()); 
			// combine the blocks
			StringBuilder add = new StringBuilder();
			for(Map.Entry<Integer,ArrayList<String>> entry : store.entrySet()) {
				ArrayList<String> strs = entry.getValue();
				Collections.sort(strs);
				for(int i = 0; i < strs.size(); ++i) {
					add.append(strs.get(i));
				}
			}
			// compress the chained
			int len = 0;
			StringBuilder res = new StringBuilder();
			for(int i = 0; i < add.length(); ++i) { // compress
				char cur = add.charAt(i);
				if(res.length() != 0 && cur == res.charAt(res.length()-1)) {
					++len;
					if(len <= m)
						res.append(cur);
				} else {
					len = 1;
					res.append(cur);
				}
			}
			System.out.println(res.toString());
		}
	}
}
