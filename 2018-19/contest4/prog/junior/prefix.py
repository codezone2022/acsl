import os
import sys

for N in range(5):
	tokens = [x for x in input().split()]
	st = [] # A list of two-item lists where the first element 'True' for operators and 'False' for operands
	for ch in tokens:
		if ch == '+' or ch == '-' or ch == '*' or ch == '@':
			st.append([True,ch])
			continue
		st.append([False,int(ch)])
		found = False
		n = len(st)
		while True:
			found = False
			n = len(st)
			if n >= 3 and st[n-3][0] and st[n-3][1] != '@' and not st[n-2][0] and not st[n-1][0]:
				# found: +/-/* operand operand
				res = 0
				if st[n-3][1] == '+':
					res = st[n-2][1] + st[n-1][1]
				if st[n-3][1] == '-':
					res = st[n-2][1] - st[n-1][1]
				if st[n-3][1] == '*':
					res = st[n-2][1] * st[n-1][1]
				st.pop()
				st.pop()
				st.pop()
				st.append([False,res])
				found = True
				n = len(st)
			if n >= 4 and st[n-4][0] and st[n-4][1] == '@' and not st[n-3][0] and not st[n-2][0] and not st[n-1][0]:
				# found: @ operand operand operand
				res = st[n-2][1] if st[n-3][1] > 0 else st[n-1][1]
				st.pop()
				st.pop()
				st.pop()
				st.pop()
				st.append([False,res])
				found = True
				n = len(st)
			if not found or n < 3: # continue evaluation for possible expressions
				break
	print(st[0][1])
