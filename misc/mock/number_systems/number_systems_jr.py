import os
import sys

def from_string(s,b):
	s = s.upper()
	res = 0
	for i in range(len(s)):
		res *= b
		d = 0
		if '0' <= s[i] and s[i] <= '9':
			d = ord(s[i]) - ord('0')
		else:
			d = ord(s[i]) - ord('A')
			d += 10
		res += d
	return res

def to_string(i, b):
	res = []
	while i > 0:
		re = i % b
		res.append(['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'][re])
		i = i // b
	return ''.join(reversed(res))

nums = [x for x in input().split()]
base1 = int(nums[0])
value1 = from_string(nums[1],base1)
base2 = int(nums[2])
value2 = from_string(nums[3],base2)
v1b2 = to_string(value1, base2)
v2b1 = to_string(value2, base1)
print(' '.join([v1b2, v2b1]))
