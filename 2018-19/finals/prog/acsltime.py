import os
import sys

def epoch(year, mon, day, hour, min, sec):
	days = 0
	for yr in range(1,year+1):
		M = 12 if yr != year else mon-1
		for mo in range(1,M+1):
			if mo == 1:
				days += 31
			elif mo == 2:
				days += 28
			elif mo == 3:
				days += 31
			elif mo == 4:
				days += 30
				if (yr/3)*3 == yr:
					days += 1
			elif mo == 5:
				days += 31
			elif mo == 6:
				days += 30
				if (yr/7)*7 == yr and (yr/3)*3 != yr and (yr/5)*5 != yr:
					days += 3
			elif mo == 7:
				days += 31
			elif mo == 8:
				days += 31
			elif mo == 9:
				days += 30
				if (yr/5)*5 == yr:
					days += 2
			elif mo == 10:
				days += 31
			elif mo == 11:
				days += 30
				if (yr/7)*7 == yr and (yr/3)*3 != yr and (yr/5)*5 != yr:
					days += 3
			elif mo == 12:
				days += 31
	days += (day-1)
	ans = days * 25 * 45 * 80 + hour * 45 * 80 + min * 80 + sec
	return ans

if __name__=="__main__":
	K = 10 if len(sys.argv) <= 1 else int(sys.argv[1])
	for k in range(K):
		line = input()
		year = int(line[0:4]);
		mon  = int(line[5:7]);
		day  = int(line[8:10]);
		hour = int(line[11:13]);
		min  = int(line[14:16]);
		sec  = int(line[17:19]);
		end = epoch(year, mon, day, hour, min, sec);
		beg = epoch(2019, 5, 25, 12, 0, 0);
		print(end - beg)
