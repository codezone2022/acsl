import os
import sys

INT_MAX = 65536

def to_string(num, base, width = INT_MAX):
	res = ''
	i = 0
	while num or width != INT_MAX:
		d = num % base
		res += str(d)
		num = num // base
		i += 1
		if i >= width:
			break
	return res[::-1] # Reverse a string efficiently in Python

for k in range(5):
	line = input()
	bs = ''
	for ch in line:
		cs = to_string(ord(ch), 2, 8)
		bs += cs
	i = 0
	while(True):
		s = to_string(i, 2)
		if s not in bs:
			break
		i += 1
	print(i - 1)
