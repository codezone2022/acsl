import os
import sys

while(True): # for batch process - do not do this in your hackerrank.com solutions
	s = ''
	m = 0
	args = []
	try:
		args = [x for x in input().split()]
	except Exception as e:
		break
	s = args[0]
	m = int(args[1])
	block = [] # Python strings are immutable - use lists as string builders
	# key: string length, val: strings with the same length - in descending order
	store = {}
	for c in s:
		if len(block) > 0 and block[len(block)-1] != c:
			if not store.get(len(block)):
				store[len(block)] = []
			store[len(block)].append(block);
			block = []
		block.append(c);
	# don't forget about the leftover
	if not store.get(len(block)):
		store[len(block)] = []
	store[len(block)].append(block);
	# combine the blocks
	add = []
	for k in reversed(sorted(store.keys())):
		strs = sorted(store.get(k))
		for s in strs:
			for c in s:
				add.append(c)
	# compress the chained
	length = 0
	res = []
	for cur in add: # compress
		if len(res) > 0 and cur == res[len(res)-1]:
			length += 1
			if length <= m:
				res.append(cur)
		else:
			length = 1
			res.append(cur)
	print(''.join(res))
