import java.io.*;
import java.util.*;

public class matrix_rotation {

	public static void print(int[][] matrix) {
		int M = matrix.length;
		int N = matrix[0].length;
		for(int r = 0; r < M; ++r) {
			for(int c = 0; c < N; ++c)
				System.out.printf("%3d", matrix[r][c]);
			System.out.println();
		}
	}

	//
	// Implement the following methods...
	//

	public static void rotate_horizontal(int[][] matrix) {
	}

	public static void rotate_vertical(int[][] matrix) {
	}

	public static void rotate_1st_diagonal(int[][] matrix) {
	}

	public static void rotate_2nd_diagonal(int[][] matrix) {
	}

	public static void spin_90degree_clockwise(int[][] matrix) {
	}

	public static void main(String[] args) {

		int[][] m1 = new int[][] {
			{ 1, 2, 3 },
			{ 4, 5, 6 },
			{ 7, 8, 9 },
		};
		System.out.println("Before rotate horizontally:");
		print(m1);
		rotate_horizontal(m1);
		System.out.println("After  rotate horizontally:");
		print(m1);

		int[][] m2 = new int[][] {
			{ 1, 2, 3 },
			{ 4, 5, 6 },
			{ 7, 8, 9 },
		};
		System.out.println("Before rotate vertically:");
		print(m2);
		rotate_vertical(m2);
		System.out.println("After  rotate vertically:");
		print(m2);

		int[][] m3 = new int[][] {
			{ 1, 2, 3 },
			{ 4, 5, 6 },
			{ 7, 8, 9 },
		};
		System.out.println("Before rotate diagonal:");
		print(m3);
		rotate_1st_diagonal(m3);
		System.out.println("After  rotate diagonal:");
		print(m3);

		int[][] m4 = new int[][] {
			{ 1, 2, 3 },
			{ 4, 5, 6 },
			{ 7, 8, 9 },
		};
		System.out.println("Before rotate 2nd diagonal:");
		print(m4);
		rotate_2nd_diagonal(m4);
		System.out.println("After  rotate 2nd diagonal:");
		print(m4);

		int[][] m5 = new int[][] {
			{ 1, 2, 3 },
			{ 4, 5, 6 },
			{ 7, 8, 9 },
		};
		System.out.println("Before spinning 90 degree clockwise:");
		print(m5);
		spin_90degree_clockwise(m5);
		System.out.println("After  spinning 90 degree clockwise:");
		print(m5);
	}
}

