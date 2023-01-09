import java.io.*;
import java.util.*;

public class fibonacci_clock {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) { // This loop is not needed on hackerrank.com!
			char lower_one, upper_one, two, three, five;
			lower_one = input.next().charAt(0);
			upper_one = input.next().charAt(0);
			two = input.next().charAt(0);
			three = input.next().charAt(0);
			five = input.next().charAt(0);
			input.nextLine();
			int hour = 0, min = 0;
			// red
			if(lower_one == 'R') hour += 1;
			if(upper_one == 'R') hour += 1;
			if(two == 'R') hour += 2;
			if(three == 'R') hour += 3;
			if(five == 'R') hour += 5;
			// green
			if(lower_one == 'G') min += 1;
			if(upper_one == 'G') min += 1;
			if(two == 'G') min += 2;
			if(three == 'G') min += 3;
			if(five == 'G') min += 5;
			// blue
			if(lower_one == 'B') { hour += 1; min += 1; }
			if(upper_one == 'B') { hour += 1; min += 1; }
			if(two == 'B') { hour += 2; min += 2; }
			if(three == 'B') { hour += 3; min += 3; }
			if(five == 'B') { hour += 5; min += 5; }
			min *= 5;
			if(min >= 60) { hour += (min/60); min %= 60; }
			if(hour > 11) hour %= 12;
			System.out.format("%02d:%02d\n", hour, min);
		}
	}
}
