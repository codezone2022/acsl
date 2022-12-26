import os
import sys

while True:
	N = 0
	M = 0
	try:
		N,M = [int(x) for x in input().split()]
	except EOFError as e:
		break
	arr = [[[0]*M for i in range(N)] for k in range(3)] # creates a matrix of 3xNxM
	for k in range(3):
		nums = [int(x) for x in input().split()]
		idx = 0
		for i in range(N):
			for j in range(M):
				arr[k][i][j] = nums[idx]
				idx += 1
	res = 0
	i = 0
	j = 0
	while i < N and j < M:
		res += min(arr[0][i][j], arr[1][i][j], arr[2][i][j])
		if i == N -1 or j == M - 1:
			break
		max_val = max(
			arr[0][i][j+1], arr[0][i+1][j],
			arr[1][i][j+1], arr[1][i+1][j],
			arr[2][i][j+1], arr[2][i+1][j])
		cnt = 0
		if max_val == arr[0][i][j+1]:
			cnt += 1
		if max_val == arr[0][i+1][j]:
			cnt += 1
		if max_val == arr[1][i][j+1]:
			cnt += 1
		if max_val == arr[1][i+1][j]:
			cnt += 1
		if max_val == arr[2][i][j+1]:
			cnt += 1
		if max_val == arr[2][i+1][j]:
			cnt += 1
		if cnt > 1:
			i += 1
			j += 1
		elif max_val == arr[0][i][j+1] or max_val == arr[0][i][j+1] or max_val == arr[1][i][j+1] or max_val == arr[2][i][j+1]:
			j += 1
		else:
			i += 1
	print(res)
