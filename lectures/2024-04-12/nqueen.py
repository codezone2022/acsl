import os
import sys

def printQueens(board, N):
	print('-'*N*2) # Dividor line between two solutions
	for row in range(N): # 'row' or 'col' does not matter which one is which here
		for col in range(N):
			if col+1 == board[row]:
				print('Q',end=' ')
			else:
				print('*',end=' ')
		print()

# Check if the n-th queen placed has no conflicts with other queens
def canPlace(board, n):
	# The board is an 1D array where each element is the 1-base indice of the queen piece
	for i in range(n):
		if board[n] == board[i] or abs(board[i]-board[n]) == abs(n - i):
			return False
	return True

def backtrack(board, N, step):
	if step >= N:
		printQueens(board, N) # Found a solution!
		return
	for i in range(1,N+1): # For each of the candidates
		board[step] = i # Place a queen candidate
		if canPlace(board, step):
			backtrack(board, N, step+1)
		board[step] = 0 # Remove the queen candidate

N = 8 # N number of queens
print('{0}-queen chess solution(s):'.format(N))
board = [0]*N
backtrack(board, N, 0)
