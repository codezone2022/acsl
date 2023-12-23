import java.io.*;
import java.util.*;

public class enclosure {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) { // read 5 input cases
			String exp = input.nextLine();
			ArrayList<Integer> res = new ArrayList<Integer>();
			if(exp.indexOf(")") < 0) { // has left missing right
				int beg = exp.indexOf("("); int end = exp.length();
				for(int i = beg+1; i < end; ++i) {
					char c = exp.charAt(i);
					if(c == '+' || c == '-' || c == '*' || c == '/')
						res.add(i+3);
				}
			} else if(exp.indexOf("(") < 0) { // has right missing left
				int beg = 0; int end = exp.indexOf(")");
				for(int i = beg; i < end; ++i) {
					char c = exp.charAt(i);
					if(c == '+' || c == '-' || c == '*' || c == '/')
						res.add(i);
				}
			}
			for(int i = 0; i < res.size(); ++i) {
				System.out.print(res.get(i));
				if(i != res.size()-1) {
					System.out.print(", ");
				}
			}
			System.out.println();
		}
	}
}
