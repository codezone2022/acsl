import java.io.*;
import java.util.*;

public class triangle {
	private static int digital_root(int num) {
		int res = 0;
		while(num >= 10) {
			res += (num % 10);
			num /= 10;
			if(num < 10) {
				res += num;
				num = res;
				res = 0;
			}
		}
		return num;
	}

	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) { // read 5 input cases
			int s = input.nextInt();
			int d = input.nextInt();
			int r = input.nextInt();
			input.nextLine();
			int sum = 0;
			int num = s;
			for(int i = 0; i < r; ++i) {
				sum = 0;
				for(int j = 0; j <= i; ++j) {
					num = digital_root(num);
					sum += num;
					num += d;
				}
			}
			System.out.println(sum);
		}
	}
}
