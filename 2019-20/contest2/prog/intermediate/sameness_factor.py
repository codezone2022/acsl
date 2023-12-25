import os
import sys

def calc(a, b):
	res = 0
	for i in range(min(len(a), len(b))):
		res += (ord(a[i]) - ord(b[i]))
	return res + abs(len(a) - len(b))

for n in range(5):
	one,two = input().strip().split()
	while True:
		old_one = one[:] # string deep copy
		old_two = two[:] # string deep copy
		new_one = ""
		new_two = ""

		# Delete the like characters in the like locations
		i = 0
		j = 0
		N = max(len(one), len(two))
		while i < N or j < N:
			if i < len(one) and j < len(two) and one[i] == two[j]:
				i += 1
				j += 1
				continue
			if i < len(one):
				new_one += one[i]
			if j < len(two):
				new_two += two[j]
			i += 1
			j += 1

		one = new_one
		two = new_two;
		new_one = ""
		new_two = ""

		# Delete for alignments
		i = 0
		j = 0
		N = max(len(one), len(two))
		while i < N or j < N:
			if i < len(one) and j < len(two) and one[i] != two[j]:
				if j < len(two)-1 and one[i] == two[j+1]:
					i += 1
					j += 2
					continue
				if i < len(one)-1 and one[i+1] == two[j]:
					i += 2
					j += 1
					continue
			if i < len(one):
				new_one += one[i]
			if j < len(two):
				new_two += two[j]
			i += 1
			j += 1

		if old_one == new_one and old_two == new_two:
			break
		one = new_one
		two = new_two
	print(calc(one, two))
