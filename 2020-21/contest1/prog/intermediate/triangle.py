import os
import sys

def digit_sum_octal(num):
	s = oct(num)[2:]
	res = 0
	for ch in s:
		res += (ord(ch) - ord('0'))
	return res

while(True): # You don't have to do this on hackerrank.com!
	s = 0
	d = 0
	r = 0
	try:
		strs = [x for x in input().split()]
		s,d,r = [int(strs[0],8), int(strs[1],8), int(strs[2])]
	except EOFError as e:
		break
	res = 0
	for i in range(1, r):
		for j in range(0,i+1):
			s += d
			if i == r-1: # last row
				res += digit_sum_octal(s)
	print(res)
