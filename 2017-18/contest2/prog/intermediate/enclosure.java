import java.io.*;
import java.util.*;

// Missing (: locations on the left of the first digit but the number has no ), starting from [ stopping by )
// Missing ): locations on the operators or ], starting from ( stopping by ] inclusive
// Missing [: locations on the left of ( or the first digit, starting from the begin of string stopping by ( inclusive
// Missing ]: locations on the operators or ) or end of string, starting from ) stopping by the end of string

public class enclosure {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) { // read 5 input cases
			String exp = input.nextLine();
			int leftpos = exp.indexOf("(");
			int rightpos = exp.indexOf(")");
			ArrayList<Integer> res = new ArrayList<Integer>();
			if(exp.indexOf("(") < 0) { // Missing (
				int beg = exp.indexOf("["); int end = exp.indexOf(")");
				char pre = '\0';
				for(int i = beg + 1; i < end; ++i) {
					char cur = exp.charAt(i);
					if(Character.isDigit(cur) && !Character.isDigit(pre) &&
							exp.charAt(i+1) != ')' && exp.charAt(i+2) != ')')
						res.add(i+1);
					pre = cur;
				}
			} else if(exp.indexOf(")") < 0) { // Missing )
				int beg = exp.indexOf("("); int end = exp.indexOf("]");
				for(int i = beg + 1; i <= end; ++i) {
					char cur = exp.charAt(i);
					if(cur == ']' ||
							((cur == '+' || cur == '-' || cur == '*' || cur == '/') &&
							exp.charAt(i-2) != '(' && exp.charAt(i-3) != '('))
						res.add(i+1);
				}
			} else if(exp.indexOf("[") < 0) { // Missing [
				int beg = 0; int end = exp.indexOf("(");
				char pre = '\0';
				for(int i = beg; i <= end; ++i) {
					char cur = exp.charAt(i);
					if((Character.isDigit(cur) && !Character.isDigit(pre)) || cur == '(')
						res.add(i+1);
					pre = cur;
				}
			} else if(exp.indexOf("]") < 0) { // Missing ]
				int beg = exp.indexOf(")"); int end = exp.length();
				for(int i = beg; i < end; ++i) {
					char cur = exp.charAt(i);
					if(cur == ')' || i == end - 1) {
						if(res.isEmpty() || res.get(res.size()-1) != i+2)
							res.add(i+2);
					} else if(cur == '+' || cur == '-' || cur == '*' || cur == '/') {
						if(res.isEmpty() || res.get(res.size()-1) != i+1)
							res.add(i+1);
					}
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
