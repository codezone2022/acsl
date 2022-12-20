import os
import sys

N = 10 if len(sys.argv) < 2 else int(sys.argv[1])
for n in range(N):
	text = input()
	line = []
	for ch in text:
		# I don't know why Python has no isalphanumeric() function...
		if (ord('A') <= ord(ch) and ord(ch) <= ord('Z')) or (ord('a') <= ord(ch) and ord(ch) <= ord('z')) or (ord('0') <= ord(ch) and ord(ch) <= ord('9')):
			line.append(ch)
	sort = sorted(line)
	cnt = 0;
	j = 0
	h = 0
	t = len(line) - 1
	while line != sort:
		if j%2==0: # Swap smallest character not in position
			while h < len(line):
				if line[h] != sort[h]:
					found = h
					while line[found] != sort[h]:
						found += 1
					temp = line[h]
					line[h] = line[found]
					line[found] = temp
					cnt += 1
					break
				h += 1
		else: # Swap largest character not in position
			while t >= 0:
				if line[t] != sort[t]:
					found = t
					while line[found] != sort[t]:
						found -= 1
					temp = line[t]
					line[t] = line[found]
					line[found] = temp
					cnt += 1
					break
				t -= 1
		j += 1
	print(cnt)
