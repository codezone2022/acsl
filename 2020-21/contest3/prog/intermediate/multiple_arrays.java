import java.io.*;
import java.util.*;

public class multiple_array {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(true) {
			int N,M;
			try {
				N = input.nextInt();
				M = input.nextInt();
			} catch(Exception e) {
				break; // exit the program
			}
			int[][][] arr = new int[3][N][M];
			for(int k = 0; k < 3; ++k) {
				for(int i = 0; i < N; ++i) {
					for(int j = 0; j < M; ++j) {
						arr[k][i][j] = input.nextInt();
					}
				}
			}
			input.nextLine();
			int res = 0;
			for(int i = 0, j = 0; i < N && j < M;) {
				res += Math.min(arr[0][i][j], Math.min(arr[1][i][j], arr[2][i][j]));
				if(i == N -1 || j == M - 1)
					break;
				int max_val = Math.max(
					Math.max(arr[0][i][j+1], arr[0][i+1][j]),
					Math.max(Math.max(arr[0][i][j+1], arr[0][i+1][j]),
					Math.max(Math.max(arr[1][i][j+1], arr[1][i+1][j]),
					Math.max(arr[2][i][j+1], arr[2][i+1][j]))));
				int cnt = 0;
				if(max_val == arr[0][i][j+1]) ++cnt;
				if(max_val == arr[0][i+1][j]) ++cnt;
				if(max_val == arr[1][i][j+1]) ++cnt;
				if(max_val == arr[1][i+1][j]) ++cnt;
				if(max_val == arr[2][i][j+1]) ++cnt;
				if(max_val == arr[2][i+1][j]) ++cnt;
				if(cnt > 1) {
					++i;
					++j;
				} else if(max_val == arr[0][i][j+1] || max_val == arr[1][i][j+1] || max_val == arr[2][i][j+1]) {
					++j;
				} else {
					++i;
				}
			}
			System.out.println(res);
		}
	}
}
