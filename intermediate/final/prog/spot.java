import java.io.*;
import java.util.*;

public class spot {

	public static int seq(int r, int c, int N) { return r * N + c + 1; }

	public static void place(char[][] grid, int n, char piece) {
		int N = grid.length;
		int row = (n-1)/N;
		int col = (n-1)%N;
		grid[row][col] = piece;
	}

	public static int find(char[][] grid, char piece) {
		int N = grid.length;
		for(int i = 0; i <= N-3; ++i)
			for(int j = 0; j <= N-3; ++j) {
				if(grid[i][j] == piece && grid[i][j+2] == piece && grid[i+1][j+1] == piece && grid[i+2][j+1] == piece)
					return seq(i,j,N)+seq(i,j+2,N)+seq(i+1,j+1,N)+seq(i+2,j+1,N);
				if( grid[i][j] == piece && grid[i+2][j] == piece && grid[i+1][j+1] == piece && grid[i+1][j+2] == piece)
					return seq(i,j,N)+seq(i+2,j,N)+seq(i+1,j+1,N)+seq(i+1,j+2,N);
				if( grid[i][j+2] == piece && grid[i+1][j] == piece && grid[i+1][j+1] == piece && grid[i+2][j+2] == piece)
					return seq(i,j+2,N)+seq(i+1,j,N)+seq(i+1,j+1,N)+seq(i+2,j+2,N);
				if( grid[i][j+1] == piece && grid[i+1][j+1] == piece && grid[i+2][j] == piece && grid[i+2][j+2] == piece)
					return seq(i,j+1,N)+seq(i+1,j+1,N)+seq(i+2,j,N)+seq(i+2,j+2,N);
			}
		return 0;
	}

	public static void main(String args[]) {
		int K = args.length > 0 ? Integer.parseInt(args[0]) : 10;
		Scanner input = new Scanner(System.in);
		for(int k = 0; k < K && input.hasNextLine(); ++k) {
			StringTokenizer line = new StringTokenizer(input.nextLine());
			int N = Integer.parseInt(line.nextToken());
			ArrayList<Integer> nums = new ArrayList<Integer>();
			while(line.hasMoreTokens()) {
				int num = Integer.parseInt(line.nextToken());
				nums.add(num);
			}
			char[][] grid = new char[N][N];
			int found = 0;
			for(int i = 0; i < nums.size(); ++i) {
				place(grid, nums.get(i), (i%2==1)?'C':'S');
				found = find(grid, (i%2==1)?'C':'S');
				if(found != 0)
					break;
			}
			System.out.println(found);
		}
	}
}
