import java.io.*;
import java.util.*;

public class graphs {
	public static void main(String[] args) {
		final int N = 10;
		Scanner input = new Scanner(System.in);
		while(true) { // should not have this while loop in your hackerrank.com solutions!
			String line;
			try {
				line = input.nextLine();
			} catch(Exception e) {
				break; // exit the program
			}
			boolean[][] ma = new boolean[N][N]; // adjacency matrix
			Scanner sin = new Scanner(line);
			while(sin.hasNext()) {
				String edge = sin.next();
				int from = edge.charAt(0) - '0'; int to = edge.charAt(1) - '0';
				ma[from][to] = true;
			}
			int sum = 0;
			// path: i -> j -> k
			for(int i = 1; i < N; ++i) {
				for(int j = 1; j < N; ++j) {
					if(i == j || !ma[i][j])
						continue;
					for(int k = 1; k < N; ++k) {
						if(i == k || j == k || !ma[j][k])
							continue;
						sum += (i * 100 + j * 10 + k); // found a length of 2 simple path
					}
				}
			}
			System.out.println(sum);
		}
	}
}
