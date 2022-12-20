#!/usr/bin/python3
import sys
import math

if __name__ == "__main__":
	for n in range(0,5):
		line = input().strip()
		exp = line.replace(' ','')
		res = []
		leftpos = exp.find('(')
		rightpos = exp.find(')')
		if leftpos >= 0 and rightpos < 0: # has left missing right
			for i in range(leftpos, len(exp)):
				if exp[i] == '+' or exp[i] == '-' or exp[i] == '*' or exp[i] == '/':
					res.append(i+3)
		elif leftpos < 0 and rightpos >= 0: # has right missing left
			for i in range(0, rightpos):
				if exp[i] == '+' or exp[i] == '-' or exp[i] == '*' or exp[i] == '/':
					res.append(i)
		j = 0
		for num in res:
			print(num, end = ", " if j < len(res)-1 else '\n')
			j += 1

