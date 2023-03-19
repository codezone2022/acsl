import java.io.*;
import java.util.*;

public class prefix {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for(int N = 0; N < 5; ++N) {
			String line = input.nextLine();
			ArrayList<Boolean> st0 = new ArrayList<Boolean>(); // true when the token is an operator
			ArrayList<Integer> st1 = new ArrayList<Integer>();
			for(int k = 0; k < line.length(); ++k) {
				char ch = line.charAt(k);
				if(ch == ' ')
					continue;
				if(ch == '+' || ch == '-' || ch == '*' || ch == '@') {
					st0.add(true);
					st1.add((int)ch);
					continue;
				}
				st0.add(false);
				st1.add(ch-'0');
				boolean found = false;
				int n = st1.size();
				do {
					found = false;
					n = st1.size();
					if(n >= 3 && st0.get(n-3) && st1.get(n-3) != (int)'@' && !st0.get(n-2) && !st0.get(n-1)) {
						// found: +/-/* operand operand
						int res = 0;
						char op = (char)st1.get(n-3).intValue();
						switch(op){
						case '+': res = st1.get(n-2) + st1.get(n-1); break;
						case '-': res = st1.get(n-2) - st1.get(n-1); break;
						case '*': res = st1.get(n-2) * st1.get(n-1); break;
						}
						for(int i = 0; i < 3; ++i) {
							st0.remove(st0.size()-1);
							st1.remove(st1.size()-1);
						}
						st0.add(false);
						st1.add(res);
						found = true;
						n = st1.size();
					}
					if(n >= 4 && st0.get(n-4) && st1.get(n-4) == (int)'@' && !st0.get(n-3) && !st0.get(n-2) && !st0.get(n-1)) {
						// found: @ operand operand operand
						int res = st1.get(n-3) > 0 ? st1.get(n-2) : st1.get(n-1);
						for(int i = 0; i < 4; ++i) {
							st0.remove(st0.size()-1);
							st1.remove(st1.size()-1);
						}
						st0.add(false);
						st1.add(res);
						found = true;
						n = st1.size();
					}
				} while(found && n >= 3); // continue evaluation for possible expressions
			}
			System.out.println(st1.get(st1.size()-1));
		}
	}
}
