import java.io.*;
import java.util.*;

public class stretch {

	public static int[] toRowCol(int r, int c, int s) {
		int ri = (s-1) / c;
		int ci = (s-1) % c;
		return new int[] {ri, ci};
	}

	public static int toSeqNum(int r, int c, int ri, int ci) {
		return ri * c + ci + 1;
	}

	public static boolean isValid(int r, int c, int ri, int ci) {
		return 0 <= ri && ri < r && 0 <= ci && ci < c;
	}

	public static char nextPiece(char curr) {
		char[] ps = new char[] { 'A', 'B', 'C' };
		if(curr == 0)
			return 'A';
		return ps[(curr - 'A' + 1) % 3];
	}

	public static boolean isEnd(int r, int c, int s) {
		int[] rc = toRowCol(r, c, s);
		return rc[1] == c - 1;
	}

	public static int endPole(int r, int c, int begPole, char piece) {
		int[] rc = toRowCol(r, c, begPole); int rl = rc[0]; int cl = rc[1];
		int rr = 0, cr = 0;
		switch(piece) {
		case 'A': rr = rl;   cr = cl + 2; break;
		case 'B': rr = rl+1; cr = cl + 1; break;
		case 'C': rr = rl+2; cr = cl + 1; break;
		}
		return isValid(r, c, rr, cr) ? toSeqNum(r, c, rr, cr) : 0;
	}

	public static boolean canPlace(int r, int c, boolean[] blocks, int begPole, char piece) {
		int[] rc = toRowCol(r, c, begPole);
		int ri = rc[0];
		int ci = rc[1];
		switch(piece) {
		case 'A':
			if( !isValid(r, c, ri, ci  ) || blocks[toSeqNum(r, c, ri, ci  )] || // left-pole (center cell)
				!isValid(r, c, ri, ci+1) || blocks[toSeqNum(r, c, ri, ci+1)] || // ‘A’
				!isValid(r, c, ri, ci+2) || blocks[toSeqNum(r, c, ri, ci+2)] )  // right-pole
				return false;
			break;
		case 'B':
			if(	!isValid(r, c, ri  , ci  )||blocks[toSeqNum(r, c, ri  , ci  )] || // left-pole (center cell)
				!isValid(r, c, ri+1, ci  )||blocks[toSeqNum(r, c, ri+1, ci  )] || // ‘B’
				!isValid(r, c, ri+1, ci+1)||blocks[toSeqNum(r, c, ri+1, ci+1)] )  // right-pole
				return false;
			break;
		case 'C':
			if( !isValid(r, c, ri  , ci  )||blocks[toSeqNum(r, c, ri  , ci  )] || // left-pole (center cell)
				!isValid(r, c, ri  , ci+1)||blocks[toSeqNum(r, c, ri  , ci+1)] || // Upper ‘C’
				!isValid(r, c, ri+1, ci+1)||blocks[toSeqNum(r, c, ri+1, ci+1)] || // Lower ‘C’
				!isValid(r, c, ri+2, ci+1)||blocks[toSeqNum(r, c, ri+2, ci+1)] )  // right-pole
				return false;
			break;
		}
		return true;
	}

	public static void main(String[] args) {
		int N = args.length > 1 ? Integer.parseInt(args[0]) : 5;
		Scanner input = new Scanner(System.in);
		for(int i = 0; i < N; ++i) {
			// Process input data
			StringTokenizer line = new StringTokenizer(input.nextLine());
			int r = Integer.parseInt(line.nextToken());
			int c = Integer.parseInt(line.nextToken());
			int s = Integer.parseInt(line.nextToken());
			int n = Integer.parseInt(line.nextToken());
			boolean[] blocks = new boolean[r*c+1];
			for(int j = 0; j < n; ++j) {
				int b = Integer.parseInt(line.nextToken());
				blocks[b] = true;
			}
			// Complete Search - whenever a piece can be placed, move on to the next step
			char piece = '\0';
			String res = new String();
			int ep = s;
			boolean found = false;
			while(!found) {
				for(int j = 0; j < 3 && !found; ++j) {
					piece = nextPiece(piece);
					if(canPlace(r, c, blocks, ep, piece)) {
						res += piece;
						ep = endPole(r, c, ep, piece);
						if(isEnd(r, c, ep))
							found = true;
						else
							++ep;
						break;
					}
				}
			}
			System.out.println(res);
		}
	}
}
