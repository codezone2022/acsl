#!/usr/bin/python3
import sys
import math
import re

def divide(resStr, newStr):
	found = {} # Use a hashtable/Dictionary instead of a counting array 
	str0 = []
	str1 = []
	for i in range(len(resStr)):
		ch = resStr[i]
		if found.get(ch):
			str0.append(ch)
		else:
			found[ch] = True
			str1.append(ch)
	str1 = sorted(str1)
	return [ ''.join(str0), newStr + ''.join(str1) ]

def removeDuplicate(s):
	res = ''
	for i in range(len(s)):
		if i == 0:
			res += s[i]
		elif s[i] != res[len(res)-1]:
			res += s[i]
	return res

if __name__ == "__main__":
	for n in range(0,5):
		line = input().strip()
		line = line.lower()
		line = re.sub(r'[^a-z]', '', line); # Regular Expression to remove non-lower letters
		news = ''
		while len(line) > 0:
			line,news = divide(line, news)
		print(removeDuplicate(news))
