import java.io.*;
import java.util.*;

public class acsltime {
	public static long epoch(long year, long mon, long day, long hour, long min, long sec) {
		long days = 0;
		for(long yr = 1; yr <= year; ++yr) {
			long M = yr != year ? 12 : mon-1;
			for(long mo = 1; mo <= M; ++mo) {
				switch((int)mo) {
				case  1: days += 31; break;
				case  2: days += 28; break;
				case  3: days += 31; break;
				case  4: days += 30; if((yr/3)*3==yr) ++days; break;
				case  5: days += 31; break;
				case  6: days += 30; if((yr/7)*7==yr && (yr/3)*3!=yr && (yr/5)*5!=yr) days+=3; break;
				case  7: days += 31; break;
				case  8: days += 31; break;
				case  9: days += 30; if((yr/5)*5==yr) days+=2; break;
				case 10: days += 31; break;
				case 11: days += 30; if((yr/7)*7==yr && (yr/3)*3!=yr && (yr/5)*5!=yr) days+=3; break;
				case 12: days += 31; break;
				}
			}
		}
		days += (day-1);
		long ans = days * 25 * 45 * 80 + hour * 45 * 80 + min * 80 + sec;
		return ans;
	}

	public static void main(String[] args) {
		int K = args.length > 0 ? Integer.parseInt(args[0]) : 10;
		Scanner input = new Scanner(System.in);
		for(int k = 0; k < K && input.hasNextLine(); ++k) {
			String line = input.nextLine();
			long year = Long.parseLong(line.substring(0,4));
			long mon  = Long.parseLong(line.substring(5,7));
			long day  = Long.parseLong(line.substring(8,10));
			long hour = Long.parseLong(line.substring(11,13));
			long min  = Long.parseLong(line.substring(14,16));
			long sec  = Long.parseLong(line.substring(17,19));
			long end = epoch(year, mon, day, hour, min, sec);
			long beg = epoch(2019, 5, 25, 12, 0, 0);
			System.out.println(end - beg);
		}
	}
}
