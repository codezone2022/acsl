import java.io.*;
import java.lang.*;
import java.util.*;

public class solution {

	public static int calc(String a, String b) {
		int res = 0;
		for(int i = 0; i < a.length() && i < b.length(); ++i) {
			res += ((int)a.charAt(i) - (int)b.charAt(i));
		}
		return res + Math.abs((int)a.length() - (int)b.length());
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) {
			String one = input.next();	String two = input.next(); input.nextLine();
			while(true) {
				String old_one = new String(one); String old_two = new String(two); // deep copy strings
				String new_one = new String(); String new_two = new String();

				// Delete the like characters in the like locations
				for(int i = 0, j = 0; i < one.length() || j < two.length(); ++i,++j) {
					if(i < one.length() && j < two.length() && one.charAt(i) == two.charAt(j))
						continue;
					if(i < one.length())
						new_one += one.charAt(i);
					if(j < two.length())
						new_two += two.charAt(j);
				}

				one = new_one; two = new_two;
				new_one = new String(); new_two = new String();

				// Delete for alignments
				for(int i = 0, j = 0; i < one.length() || j < two.length(); ++i,++j) {
					if(i < one.length() && j < two.length() && one.charAt(i) != two.charAt(j)) {
						if(j < two.length()-1 && one.charAt(i) == two.charAt(j+1)) {
							++j;
							continue;
						}
						if(i < one.length()-1 && one.charAt(i+1) == two.charAt(j)) {
							++i;
							continue;
						}
					}
					if(i < one.length())
						new_one += one.charAt(i);
					if(j < two.length())
						new_two += two.charAt(j);
				}

				if(old_one.equals(new_one) && old_two.equals(new_two))
					break;
				one = new_one; two = new_two;
			}
			System.out.println(calc(one, two));
		}
	}
}
