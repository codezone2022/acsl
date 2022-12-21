import java.io.*;
import java.util.*;

public class graph {
	private static void mul(int[][] A, int[][] B, int[][] C) {
		for(int m = 0; m < 10; ++m) {
			for(int p = 0; p < 10; ++p) {
				int sum = 0;
				for(int n = 0; n < 10; ++n)
					sum += A[m][n] * B[n][p];
				C[m][p] = sum;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) { // read 5 input cases
			int[][] ma = new int[10][10]; // default to all zeros
			String line = input.nextLine();
			int prop = line.charAt(0) - '0';
			for(int i = 2; i < line.length();) {
				int a = line.charAt(i++) - '0';
				int b = line.charAt(i++) - '0';
				ma[a][b] = 1;
				i++; // skip a space 
			}
			switch(prop) {
			case 1:
				{
					int res = 0;
					for(int i = 1; i < 10; ++i) {
						res += ma[i][i]; // length 1 cycles
						for(int j = i+1; j < 10; ++j)
							res += ((ma[i][j] == 1 && ma[j][i] == 1) ? 1 : 0);
					}
					System.out.println(res);
				}
				break;
			case 2:
				{
					int max_edges = 0;
					int max_sum = 0;
					for(int i = 1; i < 10; ++i) {
						int edges = 0;
						int sum = 0;
						for(int j = 1; j < 10; ++j) {
							edges += ma[i][j];
							if(ma[i][j] == 1)
								sum += (i*10+j);
						}
						if(edges > max_edges) {
							max_edges = edges;
							max_sum = sum;
						}
					}
					System.out.println(max_sum);
				}
				break;
			case 3:
				{
					int[][] mc = new int[10][10];
					mul(ma, ma, mc);
					int res = 0;
					for(int i = 0; i < 10; ++i)
						for(int j = 0; j < 10; ++j)
							res += mc[i][j];
					System.out.println(res);
				}
				break;
			}
		}
	}
}
