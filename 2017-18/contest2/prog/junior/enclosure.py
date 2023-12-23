#!/usr/bin/python3
import sys
import math

for n in range(0,5):
	exp = input().strip()
	res = []
	if ')' not in exp: # has left missing right
		for i in range(exp.find('('), len(exp)):
			if exp[i] == '+' or exp[i] == '-' or exp[i] == '*' or exp[i] == '/':
				res.append(i+3)
	elif '(' not in exp: # has right missing left
		for i in range(0, exp.find(')')):
			if exp[i] == '+' or exp[i] == '-' or exp[i] == '*' or exp[i] == '/':
				res.append(i)
	j = 0
	for num in res:
		print(num, end = ", " if j < len(res)-1 else '\n')
		j += 1
