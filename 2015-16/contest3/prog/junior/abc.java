import java.io.*;
import java.util.*;

public class abc {
	public static boolean match_given(char[][] left, char[][] right) {
		for(int r = 0; r < 3; ++r)
			for(int c = 0; c < 3; ++c)
				if(left[r][c] != '\0' && right[r][c] != '\0' && left[r][c] != right[r][c])
					return false;
		return true;
	}

	public static boolean just_once(char[][] g) {
		for(int r = 0; r < 3; ++r)
			for(int c = 0; c < 3; ++c) {
				for(int i = 0; i < 3; ++i) // check row r
					if(i != c && g[r][i] == g[r][c])
						return false;
				for(int i = 0; i < 3; ++i) // check col c
					if(i != r && g[i][c] == g[r][c])
						return false;
			}
		return true;
	}

	public static void print(char[][] g) {
		for(int r = 0; r < 3; ++r)
			for(int c = 0; c < 3; ++c)
				System.out.print(g[r][c]);
		System.out.println();
	}

	public static boolean solve(char[][] grid) {
		char[] abc = new char[] {'A', 'B', 'C'};
		for(char c1 : abc)
		for(char c2 : abc)
		for(char c3 : abc)
		for(char c4 : abc)
		for(char c5 : abc)
		for(char c6 : abc)
		for(char c7 : abc)
		for(char c8 : abc)
		for(char c9 : abc) {
			char[][] g = new char[][] { {c1, c2, c3}, {c4, c5, c6}, {c7, c8, c9} };
			if(!match_given(g, grid))
				continue;
			if(!just_once(g))
				continue;
			// Found one solution
			for(int r = 0; r < 3; ++r)
				for(int c = 0; c < 3; ++c)
					grid[r][c] = g[r][c];
			return true;
		}
		return false;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) {
			char[][] grid = new char[3][3];
			int N = input.nextInt();
			for(int i = 0; i < N; ++i) {
				int p = input.nextInt();
				char c = input.next().charAt(0);
				--p;
				grid[p/3][p%3] = c;
			}
			if(solve(grid))
				print(grid);
			else
				System.out.println("Solution not found!");
		}
	}
}
