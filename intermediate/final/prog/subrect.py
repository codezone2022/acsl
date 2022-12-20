#!/usr/bin/python3
import sys
import math

if __name__ == "__main__":
	N = 10
	if len(sys.argv) > 1:
		N = int(sys.argv[1])
	for k in range(0,N):
		nums = [int(x) for x in input().split()]
		m = nums[0]
		n = nums[1]
		idx = 2
		arr = [[0]*10 for _ in range(10)]
		for i in range(m):
			for j in range(n):
				arr[i][j] = nums[idx]
				idx += 1
		max_sum = -1 * sys.maxsize;
		# Complete Search each dxw rectangles
		for i in range(m):
			for j in range(n):
				for d in range(1,m+1):
					for w in range(1,n+1):
						if i+d <= m and j+w <= n:
							sum = 0
							for r in range(i,i+d):
								for c in range(j,j+w):
									sum += arr[r][c]
							max_sum = max(max_sum, sum)
		print(max_sum)
