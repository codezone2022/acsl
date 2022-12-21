import java.io.*;
import java.lang.*;
import java.util.*;

public class patolli {
	static public boolean isPrime(int num) {
		if(num < 2)
			return false;
		int end = (int)Math.sqrt(num);
		for(int n = 2; n <= end; ++n)
			if( (num / n) * n == num ) // divisible check
				return false;
		return true;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) {
			int[] opponent = new int[] { input.nextInt(), input.nextInt(), input.nextInt() };
			int player = input.nextInt();
			int num_rolls = input.nextInt();
			int[] rolls = new int[num_rolls];
			for(int i = 0; i < num_rolls; ++i)
				rolls[i] = input.nextInt();
			int curr = player;
			for(int r = 0; r < num_rolls; ++r) {
				int roll = rolls[r];
				int next = curr + roll;
				// Check if will land on an occupied location
				if( next == opponent[0] || next == opponent[1] || next == opponent[2] )
					continue;
				// Check if will land on target location 52
				if( next == 52 ) {
					curr = next;
					break;
				}
				// Check if will land beyond 52
				if( next > 52 )
					continue;
				// Check if will land on prime #
				if( isPrime(next) ) {
					for(int i = 0; i < 6; ++i) {
						++next;
						if( next == opponent[0] || next == opponent[1] || next == opponent[2] ) {
							--next;
							break;
						}
					}
					curr = next;
					continue;
				}
				// Check if will land on perfect square > 4
				if( next == 9 || next == 16 || next == 25 || next == 36 || next == 49 ) {
					for(int i = 0; i < 6; ++i) {
						--next;
						if( next == opponent[0] || next == opponent[1] || next == opponent[2] ) {
							++next;
							break;
						}
					}
					curr = next;
					continue;
				}
				// Check if one horizontal move followed by one vertical move
				if( (curr <  7 &&  7 < next) ||
					(curr < 12 && 12 < next) ||
					(curr < 17 && 17 < next) ||
					(curr < 22 && 22 < next) ||
					(curr < 27 && 27 < next) ||
					(curr < 35 && 35 < next) ||
					(curr < 40 && 40 < next) ||
					(curr < 45 && 45 < next) ||
					(curr < 50 && 50 < next) )
				{
					for(; next > curr; --next) {
						if( (next / roll) * roll == next && next != opponent[0] && next != opponent[1] && next != opponent[2] )
							// Unoccupied multiple of roll
							break;
					}
					curr = next;
					continue;
				}
				curr = next;
			}
			System.out.println(( curr == 52 ) ? "GAME OVER" : Integer.toString(curr));
		}
	}
}
