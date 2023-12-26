import os
import sys

def fib(one, two, n):
	n %= 20
	if n == 0:
		n = 20
	if n == 1:
		return one
	if n == 2:
		return two
	f2 = one
	f1 = two
	fn = f2 + f1
	for i in range(3, n+1):
		fn = f2 + f1
		f2 = f1
		f1 = fn
	return fn

for n in range(5):
	tokens = input().split()
	a = int(tokens[0])
	b = int(tokens[1])
	key = tokens[2]
	msg = ' '.join(tokens[3:])
	for i in range(0, len(msg)):
		ch = msg[i];
		f = fib(a, b, i+1) # Convert 0-base index to 1-base sequence
		en = ord('a') + ((ord(key) - ord('a')) + f) % 26;
		offset = ord(ch) + 3 * en;
		if i < len(msg)-1:
			print(offset, end = ' ')
		else:
			print(offset)
