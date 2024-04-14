import os
import sys

def dfsEast(board, r, c, num, area, visited):
	m = len(board)
	n = len(board[0])
	if r < 0 or r >= m or c < 0 or c >= n or board[r][c] != num:
		return area
	area = dfsEast(board, r, c+1, num, area+1, visited)
	if area >= 3:
		visited[r][c] = area # positive for east bound
	return area

def dfsSouth(board, r, c, num, area, visited):
	m = len(board)
	n = len(board[0])
	if r < 0 or r >= m or c < 0 or c >= n or board[r][c] != num:
		return area
	area = dfsSouth(board, r+1, c, num, area+1, visited)
	if area >= 3:
		visited[r][c] = area * -1 # negative for south bound
	return area

def mark(board, visited):
	m = len(board)
	n = len(board[0])
	res = False
	for i in range(m):
		for j in range(n):
			num = board[i][j]
			if num == 0: # zero for empty cell
				continue
			areaE = 0
			areaS = 0
			if visited[i][j] <= 0:
				areaE = dfsEast(board, i, j, num, 0, visited)
			if visited[i][j] >= 0:
				areaS = dfsSouth(board, i, j, num, 0, visited)
			if areaE >= 3 or areaS >= 3:
				res = True
	return res

def crush(board, visited):
	m = len(board)
	n = len(board[0])
	for c in range(n):
		temp = [0]*m
		j = m - 1
		for i in range(m):
			r = m - 1 - i
			if visited[r][c] == 0:
				temp[j] = board[r][c]
				j -= 1
		for r in range(m):
			board[r][c] = temp[r]

def candyCrush(board):
	m = len(board)
	n = len(board[0])
	visited = [[0]*n for _ in range(m)]
	while mark(board,visited):
		crush(board,visited)
		visited = [[0]*n for _ in range(m)]
	return board

########## keep the below stuff ##########

# Example1
board = [
	[110,5,112,113,114],
	[210,211,5,213,214],
	[310,311,3,313,314],
	[410,411,412,5,414],
	[5,1,512,3,3],
	[610,4,1,613,614],
	[710,1,2,713,714],
	[810,1,2,1,1],
	[1,1,2,2,2],
	[4,1,4,4,1014]]
output = [
	[0,0,0,0,0],
	[0,0,0,0,0],
	[0,0,0,0,0],
	[110,0,0,0,114],
	[210,0,0,0,214],
	[310,0,0,113,314],
	[410,0,0,213,414],
	[610,211,112,313,614],
	[710,311,412,613,714],
	[810,411,512,713,1014]]
result = candyCrush(board)
if output == result:
	print("Example1 passed")
else:
	print("Example1 failed")

# Example2
board = [[1,3,5,5,2],[3,4,3,3,1],[3,2,4,5,2],[2,4,4,5,5],[1,4,4,1,1]]
output= [[1,3,0,0,0],[3,4,0,5,2],[3,2,0,3,1],[2,4,0,5,2],[1,4,3,1,1]]
result = candyCrush(board)
if output == result:
	print("Example2 passed")
else:
	print("Example2 failed")

# Example3
board = [
	[110,5,112,113,114],
	[210,211,5,213,214],
	[310,311,3,313,314],
	[410,411,412,5,414],
	[5,1,512,3,3],
	[610,4,1,613,614],
	[710,1,2,713,714],
	[810,1,2,1,1],
	[1,1,2,2,2],
	[4,1,4,4,1014]]
output = [[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[110,0,0,0,114],[210,0,0,0,214],[310,0,0,113,314],[410,0,0,213,414],[610,211,112,313,614],[710,311,412,613,714],[810,411,512,713,1014]]
result = candyCrush(board)
if output == result:
	print("Example3 passed")
else:
	print("Example3 failed")
