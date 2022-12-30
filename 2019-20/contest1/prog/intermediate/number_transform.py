import os
import sys

# |<--- left --->|P|<--- right --->|
# abcdefghijklmnopqrstuvwxyzabcdefgh    <- sample digits
# left: unit digit of the sum between that digit and the Pth digit
# Pth: unchanged
# right: absolute value of the difference between that digit and the Pth digit
# Notice: Pth is 1-base from the right

while(True): # Don't do this in hackerrank.com!
	N = ''
	P = 0
	try:
		N,P = [x for x in input().split()]
		P = int(P)
	except EOFError:
		break # Or hit Ctrl-C to quit
	res = list(N) # Python strings are immutable but lists are
	for i in range(len(N)):
		idx = len(N) - P # convert Pth from the right to 0-base index from the left
		ith = ord(N[i]) - ord('0')
		pth = ord(N[idx]) - ord('0')
		if i < idx: # left
			res[i] = str(ith + pth)[0]
		elif i > idx: # right
			res[i] = str(abs(ith - pth))[0]
	print(''.join(res))
