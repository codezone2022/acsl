import java.io.*;
import java.util.*;

public class subrect {
	public static void main(String[] args) throws IOException {
		int N = args.length > 0 ? Integer.parseInt(args[0]) : 10;
		Scanner input = new Scanner(System.in);
		for(int k = 0; k < N && input.hasNextLine(); ++k) {
			int[][] arr = new int[10][10];
			int m = input.nextInt();
			int n = input.nextInt();
			for(int i = 0; i < m; ++i)
				for(int j = 0; j < n; ++j)
					arr[i][j] = input.nextInt();
			input.nextLine();
			int max_sum = Integer.MIN_VALUE;
			// Complete Search each dxw rectangles
			for(int i = 0; i < m; ++i) {
				for(int j = 0; j < n; ++j) {
					for(int d = 1; d <= m; ++d) {
						for(int w = 1; w <= n; ++w) {
							if(i+d <= m && j+w <= n) {
								int sum = 0;
								for(int r = i; r < i+d; ++r)
									for(int c = j; c < j+w; ++c)
										sum += arr[r][c];
								max_sum = Math.max(max_sum, sum);
							}
						}
					}
				}
			}
			System.out.println(max_sum);
		}
	}
}
