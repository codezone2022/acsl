#!/usr/local/bin/python3
import os
import sys

# Create a Pascal Triangle in the lower triangle of a matrix
# 1 1 2 3 5 8
# 1 1
# 1 2 1
# 1 3 3 1
# 1 4 6 4 1
# 1 5 ... ...
def createPascalTriangle(grid, N):
	grid[0][0] = 1 # Root/Seed
	for row in range(1,N):
		for col in range(row+1):
			grid[row][col] = (0 if col == 0 else grid[row-1][col-1]) + grid[row-1][col]

def fib(n):
	if n==1:
		return 1
	if n==2:
		return 1
	f1 = 1
	f2 = 1
	fn = f2 + f1
	for i in range(3, n+1):
		fn = f2 + f1
		f1 = f2
		f2 = fn
	return fn

def seq(f):
	n = 1
	while fib(n) != f:
		n += 1
	return n

if __name__ == "__main__":
	for n in range(5):
		f = int(input())
		N = seq(f)
		grid = [[0]*N for _ in range(N)] # Create NxN matrix of zeros
		createPascalTriangle(grid, N)
		odd = 0
		even = 0
		max_num = -1
		for i in range(N):
			num = grid[N-i-1][i]
			if num != 0:
				if num % 2 == 0:
					even += 1
				else:
					odd += 1
				max_num = max(max_num, num)
		print(f'{odd} {even} {max_num}')

