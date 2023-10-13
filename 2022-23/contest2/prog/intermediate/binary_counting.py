import os
import sys

INT_MAX = 65536

def to_string(num, base, width = INT_MAX):
	if num == 0:
		return '0'
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

def remove_left(src, sub):
	pos = src.find(sub)
	if pos < 0:
		return src
	res = ''
	for i in range(len(src)):
		if i < pos or i >= (pos + len(sub)):
			res += src[i]
	return res

def remove_right(src, sub):
	pos = src.rfind(sub)
	if pos < 0:
		return src
	res = ''
	for i in range(len(src)):
		if i < pos or i >= (pos + len(sub)):
			res += src[i]
	return res

for k in range(5):
	line = input()
	bs = ''
	for ch in line:
		cs = to_string(ord(ch), 2, 8)
		bs += cs
	i = 0
	while(True):
		s = to_string(i, 2)
		l = remove_left(bs, s)
		r = remove_right(l, s)
		if bs == r:
			break
		bs = r
		i += 1
	print(i - 1)
