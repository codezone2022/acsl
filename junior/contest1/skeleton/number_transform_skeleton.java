import java.io.*;
import java.util.*;

// TO_DO: either rename the file or the class to make it work...
public class number_transform {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) { // read 5 input cases
			long N = input.nextLong(); // [1..10^15]
			long P = input.nextLong();
			long D = input.nextLong();
			input.nextLine();
			String ns = Long.toString(N);
			//
			// TO_DO: complete your solution here...
			//
			System.out.println(ns);
		}
	}
}
