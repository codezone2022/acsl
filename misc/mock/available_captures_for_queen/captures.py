import os
import sys

for n in range(5):
	N = int(input())
	res = []
	for i in range(N):
		tokens = input().split()
		grid = [['.']*8 for _ in range(8)] # 8x8 empty chess board
		# Place the black queen
		qt = tokens[0]
		qr = ord(tokens[0][0]) - ord('a')
		qc = ord(tokens[0][1]) - ord('1')
		grid[qr][qc] = 'Q'
		K = int(tokens[1])
		tokens = tokens[2:]
		# Setup the chess board
		for k in range(K):
			p = tokens[k][0]
			r = ord(tokens[k][1]) - ord('a')
			c = ord(tokens[k][2]) - ord('1')
			grid[r][c] = p
		captured = 0
		# Sweep up
		r = qr-1
		c = qc
		while r >= 0:
			if grid[r][c] != '.':
				captured += 1
				break
			r -= 1
		# Sweep down
		r = qr+1
		c = qc
		while r < 8:
			if grid[r][c] != '.':
				captured += 1
				break
			r += 1
		# Sweep left
		r = qr
		c = qc-1
		while c >= 0:
			if grid[r][c] != '.':
				captured += 1
				break
			c -= 1
		# Sweep right
		r = qr
		c = qc+1
		while c < 8:
			if grid[r][c] != '.':
				captured += 1
				break
			c += 1
		# Sweep upper-left
		r = qr-1
		c = qc-1
		while r >= 0 and c >= 0:
			if grid[r][c] != '.':
				captured += 1
				break
			r -= 1
			c -= 1
		# Sweep upper-right
		r = qr-1
		c = qc+1
		while r >= 0 and c < 8:
			if grid[r][c] != '.':
				captured += 1
				break
			r -= 1
			c += 1
		# Sweep lower-left
		r = qr+1
		c = qc-1
		while r < 8 and c >= 0:
			if grid[r][c] != '.':
				captured += 1
				break
			r += 1
			c -= 1
		# Sweep lower-right
		r = qr+1
		c = qc+1
		while r < 8 and c < 8:
			if grid[r][c] != '.':
				captured += 1
				break
			r += 1
			c += 1
		res.append([captured,qt])
	res = sorted(res)
	last = len(res)-1
	max_captured = res[last][0]
	for i in range(len(res)):
		tk = res[i]
		captured = tk[0]
		if captured == max_captured:
			if i+1 >= len(res):
				print(tk[1])
			else:
				print(tk[1], end=' ')
			continue

