import os
import sys

def unique_fib(n): # 0-base sequence
	f0 = 1
	f1 = 2
	if n == 0:
		return f0
	if n == 1:
		return f1
	f2 = f1 + f0
	for i in range(2, n+1):
		f2 = f1 + f0
		f0 = f1
		f1 = f2
	return f2

for n in range(5):
	line = input()
	key = ord(line[0])
	for i in range(2,len(line)):
		print(int((key - ord('a') + unique_fib(i-2)) % 26 + ord('a') + ord(line[i])),
			end = ' ' if i < len(line)-1 else '\n')
