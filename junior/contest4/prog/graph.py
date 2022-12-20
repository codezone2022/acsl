#!/usr/bin/python3
import sys
import math

# AB = C
def multiply(N,A,B,C):
	for m in range(N):
		for p in range(N):
			total = 0
			for n in range(N):
				total += A[m][n] * B[n][p]
			C[m][p] = total

if __name__ == "__main__":
	for n in range(0,5):
		# Create a 10x10 matrix with all zeros in one line
		ma = [[0]*10 for i in range(10)]
		# Read all numbers into a list of strings
		nums = [x for x in input().split()]
		prop = int(nums[0])
		# Create the adjacency matrix
		for i in range(1,len(nums)):
			ma[int(nums[i][0])][int(nums[i][1])] = 1
		if prop == 1:
			res = 0
			for i in range(1,10):
				res += ma[i][i] # length of 1 cycles
				for j in range(i+1,10): # length of 2 cycles
					res += (1 if ma[i][j] == 1 and ma[j][i] == 1 else 0)
			print(res)
		elif prop == 2:
			max_edges = 0
			max_total = 0
			for i in range(1,10):
				edges = 0
				total = 0
				for j in range(1,10):
					edges += ma[i][j]
					if ma[i][j] == 1:
						total += (i*10+j)
				if edges > max_edges:
					max_edges = edges
					max_total = total
			print(max_total)
		elif prop == 3:
			mc = [[0]*10 for i in range(10)] # DO NOT DO THIS -> [[0]*10]*10
			multiply(10,ma,ma,mc)
			res = 0
			for i in range(1,10):
				for j in range(1,10):
					res += mc[i][j]
			print(res)
