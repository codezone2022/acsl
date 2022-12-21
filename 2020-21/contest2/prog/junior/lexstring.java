import java.io.*;
import java.util.*;

public class lexstring {
	public static String[] divide(String[] strs) {
		boolean[] cnts = new boolean[26];
		StringBuilder res = new StringBuilder();
		StringBuilder add = new StringBuilder();
		for(int i = 0; i < strs[0].length(); ++i) {
			char ch = strs[0].charAt(i);
			int idx = ch - 'a';
			if(!cnts[idx]) {
				cnts[idx] = true;
				add.append(ch); // first appearance
			} else {
				res.append(ch); // re-appearance
			}
		}
		char[] arr = add.toString().toCharArray();
		Arrays.sort(arr);
		StringBuilder ns = new StringBuilder();
		ns.append(strs[1]);
		ns.append(String.valueOf(arr));
		return new String[] { res.toString(), ns.toString() };
	}

	public static String removeDuplicate(String str) {
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < str.length(); ++i) {
			char ch = str.charAt(i);
			if(sb.length() == 0) {
				sb.append(str.charAt(i));
			} else if(sb.charAt(sb.length()-1) != ch) {
				sb.append(str.charAt(i));
			}
		}
		return sb.toString();
	}

	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) { // read 5 input cases
			String line = input.nextLine();
			line = line.toLowerCase();
			line = line.replaceAll("[^a-z]",""); // regex to remove all none lower case letters
			//StringBuilder sb = new StringBuilder();
			//for(int i = 0; i < line.length(); ++i)
			//	if(Character.isLowerCase(line.charAt(i)))
			//		sb.append(line.charAt(i));
			//line = sb.toString();
			String[] strs = new String[] { line, "" };
			do {
				strs = divide(strs);
			} while(!strs[0].isEmpty());
			System.out.println(removeDuplicate(strs[1]));
		}
	}
}
