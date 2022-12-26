import os
import sys

N = 10

while(True):
	line = ''
	try:
		line = input()
	except EOFError as e:
		break
	ma = [[False]*N for i in range(N)] # adjacency matrix
	for edge in line.split():
		beg = ord(edge[0]) - ord('0')
		end = ord(edge[1]) - ord('0')
		ma[beg][end] = True
	total = 0
	for i in range(1,N):
		for j in range(1,N):
			if i == j or not ma[i][j]:
				continue
			for k in range(1,N):
				if i == k or j == k or not ma[j][k]:
					continue
				total += (i * 100 + j * 10 + k)
	print(total)
