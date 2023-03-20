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

	public static void setMarker(int curr, int next, int[] players) {
		for(int i = 0; i < players.length; ++i) {
			if(curr == players[i]) {
				players[i] = next;
				break;
			}
		}
	}

	public static boolean occupied(int curr, int next, int[] players) {
		for(int i = 0; i < players.length; ++i) {
			if(curr == players[i])
				continue;
			if(next == players[i])
				return true;
		}
		return false;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for(int n = 0; n < 5; ++n) {
			int[] opponent = new int[] { input.nextInt(), input.nextInt(), input.nextInt() };
			int[] players = new int[] { input.nextInt(), input.nextInt(), input.nextInt() };
			int num_rolls = input.nextInt();
			int[] rolls = new int[num_rolls];
			for(int i = 0; i < num_rolls; ++i)
				rolls[i] = input.nextInt();
			for(int r = 0; r < num_rolls; ++r) {
				int curr = Math.min(Math.min(players[0],players[1]),players[2]);
				if(curr == 52)
					break;
				int roll = rolls[r];
				int next = curr + roll;
				// Check if will land on an occupied location
				if( next == opponent[0] || next == opponent[1] || next == opponent[2] || occupied(curr, next, players) )
					continue;
				// Check if will land on target location 52
				if( next == 52 ) {
					setMarker(curr, next, players);
					break;
				}
				// Check if will land beyond 52
				if( next > 52 )
					continue;
				// Check if will land on prime #
				if( isPrime(next) ) {
					for(int i = 0; i < 6; ++i) {
						++next;
						if( next == opponent[0] || next == opponent[1] || next == opponent[2] || occupied(curr, next, players) ) {
							--next;
							break;
						}
					}
					setMarker(curr, next, players);
					continue;
				}
				// Check if will land on perfect square > 4
				if( next == 9 || next == 16 || next == 25 || next == 36 || next == 49 ) {
					for(int i = 0; i < 6; ++i) {
						--next;
						if( next == opponent[0] || next == opponent[1] || next == opponent[2] || occupied(curr, next, players) ) {
							++next;
							break;
						}
					}
					setMarker(curr, next, players);
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
						if( (next / roll) * roll == next && next != opponent[0] && next != opponent[1] && next != opponent[2] && !occupied(curr, next, players) )
							// Unoccupied multiple of roll
							break;
					}
					setMarker(curr, next, players);
					continue;
				}
				setMarker(curr, next, players);
			}
			Arrays.sort(players);
			if(players[0] == 52 && players[1] == 52 && players[2] == 52)
				System.out.println("GAME OVER");
			else {
				for(int player : players)
					if(player == 52)
						break;
					else {
						System.out.print(player);
						System.out.print(' ');
					}
				System.out.println();
			}
		}
	}
}
