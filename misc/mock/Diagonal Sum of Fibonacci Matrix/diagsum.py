#!/usr/local/bin/python3
import os
import sys
import math

def fib(num):
	if num == 0:
		return 1
	elif num == 1:
		return 1
	else:
		return fib(num-1)+fib(num-2)

def createMatrix(grid, N):
	for row in range(N):
		for col in range(N):
			num = row * N + col
			grid[row][col] = fib(num)

def diagsum(grid, N, row, col):
	res = []
	s = grid[row][col] # Center
	r = row-1
	c = col-1
	while r >= 0 and c >= 0:
		s += grid[r][c]
		r -= 1
		c -= 1
	r = row-1
	c = col+1
	while r >= 0 and c < N:
		s += grid[r][c]
		r -= 1
		c += 1
	r = row+1
	c = col-1
	while r < N and c >= 0:
		s += grid[r][c]
		r += 1
		c -= 1
	r = row+1
	c = col+1
	while r < N and c < N:
		s += grid[r][c]
		r += 1
		c += 1
	return s

for i in range(5):
	N,row,col = [int(x) for x in input().split()]
	a = [[0]*N for _ in range(N)]
	createMatrix(a, N)
	s = diagsum(a, N, row, col)
	print(s)
