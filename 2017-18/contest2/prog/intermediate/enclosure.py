#!/usr/bin/python3
import sys
import math

# Missing (: locations on the left of the first digit but the number has no ), starting from [ stopping by )
# Missing ): locations on the operators or ], starting from ( stopping by ] inclusive
# Missing [: locations on the left of ( or the first digit, starting from the begin of string stopping by ( inclusive
# Missing ]: locations on the operators or ) or end of string, starting from ) stopping by the end of string

if __name__ == "__main__":
	for n in range(0,5):
		exp = input().strip()
		res = []
		if '(' not in exp: # Missing (
			beg = exp.find('[')
			end = exp.find(')')
			pre = ' '
			for i in range(beg + 1, end):
				cur = exp[i]
				if cur.isdigit() and not pre.isdigit() and exp[i+1] != ')' and exp[i+2] != ')':
					res.append(i+1)
				pre = cur
		elif ')' not in exp: # Missing )
			beg = exp.find('(')
			end = exp.find(']')
			for i in range(beg + 1, end + 1):
				cur = exp[i]
				if cur == ']' or ((cur == '+' or cur == '-' or cur == '*' or cur == '/') and exp[i-2] != '(' and exp[i-3] != '('):
					res.append(i+1)
		elif '[' not in exp: # Missing [
			beg = 0
			end = exp.find('(')
			pre = ' '
			for i in range(beg, end + 1):
				cur = exp[i]
				if (cur.isdigit() and not pre.isdigit()) or cur == '(':
					res.append(i+1)
				pre = cur
		elif ']' not in exp: # Missing ]
			beg = exp.find(')')
			end = len(exp)
			for i in range(beg, end):
				cur = exp[i]
				if cur == ')' or i == end-1:
					if len(res) == 0 or res[len(res)-1] != i+2:
						res.append(i+2)
				elif cur == '+' or cur == '-' or cur == '*' or cur == '/':
					if len(res) == 0 or res[len(res)-1] != i+1:
						res.append(i+1)
		j = 0
		for num in res:
			print(num, end = ", " if j < len(res)-1 else '\n')
			j += 1

