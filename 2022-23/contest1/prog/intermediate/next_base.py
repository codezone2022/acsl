import os
import sys

def str_to_int(s, base):
	res = 0
	N = len(s)
	for i in range(N):
		res += (int(s[N-i-1]) * pow(base, i))
	return res

for k in range(5):
	args = [x for x in input().split()]
	n = int(args[0])
	b = int(args[1])
	s = args[2]
	num = str_to_int(s, b)
	tot = 0
	cnts = [0]*b
	for i in range(n):
		numi = num + i
		while numi > 0:
			d = numi % b
			++cnts[d]
			numi = numi // b
	print(cnts[b-1])
