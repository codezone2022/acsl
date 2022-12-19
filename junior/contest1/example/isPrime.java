import java.io.*;
import java.util.*;

public class IsPrime {

	public static boolean isPrime(int num) {
		if (num == 2)
			return true;
		if (num < 2 || num % 2 == 0)
			return false;
		for (int i = 3; i <= Math.sqrt(num); i += 2)
			if (num % i == 0)
				return false;
		return true;
	}

	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		String line = input.nextLine();
		int sum = 0;
		for(int i = 0; i < line.length(); ++i) {
			sum += (line.charAt(i) - '0');
		}
		System.out.print(sum);
		if(isPrime(sum))
			System.out.println(" yes");
		else
			System.out.println(" no");
	}
}
