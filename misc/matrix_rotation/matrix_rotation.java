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

	public static void rotate_horizontal(int[][] matrix) {
		int N = matrix.length;
		for(int r = 0; r < N; ++r) {
			for(int c = 0; c < matrix[r].length / 2; ++c) {
				int temp = matrix[r][c];
				matrix[r][c] = matrix[r][N-1-c];
				matrix[r][N-1-c] = temp;
			}
		}
	}

	public static void rotate_vertical(int[][] matrix) {
		int N = matrix.length;
		for(int r = 0; r < N / 2; ++r) {
			for(int c = 0; c < matrix[r].length; ++c) {
				int temp = matrix[r][c];
				matrix[r][c] = matrix[N-1-r][c];
				matrix[N-1-r][c] = temp;
			}
		}
	}

	public static void rotate_1st_diagonal(int[][] matrix) {
		int N = matrix.length;
		for(int r = 0; r < N; ++r) {
			for(int c = r; c < N; ++c) {
				int temp = matrix[r][c];
				matrix[r][c] = matrix[c][r];
				matrix[c][r] = temp;
			}
		}
	}

	public static void rotate_2nd_diagonal(int[][] matrix) {
		int N = matrix.length;
		for(int r = 0; r < N; ++r) {
			for(int c = 0; c < N-r; ++c) {
				int temp = matrix[r][c];
				matrix[r][c] = matrix[N-1-c][N-1-r];
				matrix[N-1-c][N-1-r] = temp;
			}
		}
	}

	public static void spin_90degree_clockwise(int[][] matrix) {
		rotate_1st_diagonal(matrix);
		rotate_horizontal(matrix);
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

