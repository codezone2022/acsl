import java.io.*;
import java.util.*;

public class FibonacciPascal {

	// Create a Pascal Triangle in the lower triangle of an NxN matrix, e.g.
	// 1 1 2 3 5 8
	// 1 1
	// 1 2 1
	// 1 3 3 1
	// 1 4 6 4 1
	// 1 5 ... ...
	public static void createPascalTriangle(int[][] grid, int N) {
		grid[0][0] = 1; // Root/Seed
		for(int row = 1; row < N; ++row)
			for(int col = 0; col < row + 1; ++col)
				if(col == 0)
					grid[row][col] = grid[row-1][col];
				else
					grid[row][col] = grid[row-1][col] + grid[row-1][col-1];
	}

	// n is 1-base sequence
	public static int fib(int n) {
		int f1 = 1; if(n==1) return f1;
		int f2 = 1; if(n==2) return f2;
		int fn = f2 + f1;
		for(int i = 3; i <= n; ++i) {
			fn = f1 + f2;
			f1 = f2; f2 = fn;
		}
		return fn;
	}

	// find 1-base sequence for the given fibonacci number
	public static int seq(int f) {
		int n = 1;
		while(fib(n) != f) ++n;
		return n;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for(int i = 0; i < 5; ++i) { // read 5 input cases
			int fib = input.nextInt();
			int N = seq(fib);
			int[][] grid = new int[N][N];
			createPascalTriangle(grid, N);
			// Print the 2nd diagonal line from lower-left
			for(int n = 0; n < N; ++n) {
				if(grid[N-1-n][n] > 0) {
					System.out.print(grid[N-1-n][n]);
					System.out.print(' ');
					continue;
				} else {
					System.out.println();
					break;
				}
			}
		}
	}
}
