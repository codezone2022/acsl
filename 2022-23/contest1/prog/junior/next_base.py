import os
import sys

def str_to_int(s, base):
	res = 0
	N = len(s)
	for i in range(N):
		res += ((ord(s[N-i-1]) - ord('0')) * pow(base, i))
	return res

def digit_sum(num, base):
	res = 0
	while num > 0:
		d = num % base
		res += d
		num = num // base
	return res

for k in range(5):
	args = [x for x in input().split()]
	n = int(args[0])
	b = int(args[1])
	s = args[2]
	num = str_to_int(s, b)
	tot = 0
	for i in range(n):
		ds = digit_sum(num+i, b)
		tot += ds;
	print(tot)
