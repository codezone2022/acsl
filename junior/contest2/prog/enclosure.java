import java.io.*;
import java.util.*;

public class enclosure {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) { // read 5 input cases
			String line = input.nextLine();
			line = line.replaceAll("\\s",""); // remove spaces by replace with empty strings
			char[] exp = line.toCharArray();
			int leftpos = line.indexOf("(");
			int rightpos = line.indexOf(")");
			ArrayList<Integer> res = new ArrayList<Integer>();
			if(leftpos >= 0 && rightpos < 0) { // has left missing right
				for(int i = leftpos; i < exp.length; ++i) {
					char c = exp[i];
					switch(c) {
					case '+':
					case '-':
					case '*':
					case '/':
						res.add(i+3);
						break;
					}
				}
			} else if(leftpos < 0 && rightpos >= 0) { // has right missing left
				for(int i = 0; i < rightpos; ++i) {
					char c = exp[i];
					switch(c) {
					case '+':
					case '-':
					case '*':
					case '/':
						res.add(i);
						break;
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
