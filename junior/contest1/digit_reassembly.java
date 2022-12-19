import java.io.*;
import java.util.*;

public class digit_reassembly {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		// 10^50 is too big for 'long' so use a string to handle
		String[] lines = new String[5];
		for(int n = 0; n < 5; ++n) { // read 5 input cases
			lines[n] = input.nextLine();
		}
		System.out.println(lines[0].length()); // line#1
		long sum = 0;
		for(int i = 0; i < lines[1].length(); ++i) {
			sum += (lines[1].charAt(i) - '0');
		}
		System.out.println(sum); // line#2
		sum = 0;
		for(int i = 0; i < lines[2].length(); ++i,++i) {
			sum += (lines[2].charAt(i) - '0');
		}
		System.out.println(sum); // line#3
		sum = 0;
		for(int i = 0; i < lines[3].length(); ++i) {
			if('4' == lines[3].charAt(i))
				++sum;
		}
		System.out.println(sum); // line#4
		int len = lines[4].length();
		int mid = (len & 1) == 0 ? len/2-1 : len/2; 
		System.out.println(lines[4].charAt(mid)); // line#5
	}
}
