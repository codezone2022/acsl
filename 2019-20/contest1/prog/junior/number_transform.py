import os
import sys

for n in range(5):
	N,P,D = [int(x) for x in input().split()]
	ns = list(reversed(str(N))) # Python strings are also immutable
	pth = ord(ns[P-1]) - ord('0') # use ord() for Python character ASCII arithmetics
	if 0 <= pth and pth <= 4: # [0..4]
		pth += D
		ns[P-1] = str(pth % 10)[0]
		for i in range(P-1):
			ns[i] = '0'
	else: # [5..9]
		pth -= D
		pth = abs(pth)
		ns[P-1] = str(pth)[0]
	for i in range(P-1):
		ns[i] = '0'
	print(''.join(reversed(ns))) # convert the list of characters to a string
