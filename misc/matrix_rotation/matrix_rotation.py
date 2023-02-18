#!/usr/bin/python3
import sys

# Print MxN matrix row by col
def print_matrix(matrix):
	M = len(matrix)
	N = len(matrix[0])
	if M == 0 or N == 0:
		return;
	for r in range(M):
		for c in range(N):
			print("{0:3}".format(matrix[r][c]),end='')
		print()

# Rotate horizontally
def rotate_horizontal(matrix):
	M = len(matrix)
	N = len(matrix[0])
	for r in range(M):
		for c in range(N // 2):
			temp = matrix[r][c]
			matrix[r][c] = matrix[r][N-1-c]
			matrix[r][N-1-c] = temp

# Rotate vertically
def rotate_vertical(matrix):
	M = len(matrix)
	N = len(matrix[0])
	for r in range(M // 2):
		for c in range(N):
			temp = matrix[r][c]
			matrix[r][c] = matrix[N-1-r][c]
			matrix[N-1-r][c] = temp

# Rotate by first diagonal
def rotate_1st_diagonal(matrix):
	N = len(matrix)
	for r in range(N):
		for c in range(r+1,N):
			if(r == c):
				continue
			temp = matrix[r][c]
			matrix[r][c] = matrix[c][r]
			matrix[c][r] = temp

# Rotate by second diagonal
def rotate_2nd_diagonal(matrix):
	N = len(matrix)
	for r in range(N):
		for c in range(N-1-r):
			if(r == N-1-c):
				continue
			temp = matrix[r][c]
			matrix[r][c] = matrix[N-1-c][N-1-r]
			matrix[N-1-c][N-1-r] = temp

def spin_90degree_clockwise(matrix):
	rotate_2nd_diagonal(matrix)
	rotate_vertical(matrix)

if __name__ == "__main__":

	# Rotate horizontally
	m1 = [
		[ 1, 2, 3 ],
		[ 4, 5, 6 ],
		[ 7, 8, 9 ],
	]
	print("Before rotate horizontally:")
	print_matrix(m1)
	rotate_horizontal(m1)
	print("After  rotate horizontally:")
	print_matrix(m1)
	print()

	# Rotate vertically
	m2 = [
		[ 1, 2, 3 ],
		[ 4, 5, 6 ],
		[ 7, 8, 9 ],
	]
	print("Before rotate vertically:")
	print_matrix(m2)
	rotate_vertical(m2)
	print("After  rotate vertically:")
	print_matrix(m2)
	print()

	# Rotate by first diagonal
	m3 = [
		[ 1, 2, 3 ],
		[ 4, 5, 6 ],
		[ 7, 8, 9 ],
	]
	print("Before rotate 1st diagonal:")
	print_matrix(m3)
	rotate_1st_diagonal(m3)
	print("After  rotate 1st diagonal:")
	print_matrix(m3)
	print()

	# Rotate by second diagonal
	m4 = [
		[ 1, 2, 3 ],
		[ 4, 5, 6 ],
		[ 7, 8, 9 ],
	]
	print("Before rotate 2nd diagonal:")
	print_matrix(m4)
	rotate_2nd_diagonal(m4)
	print("After  rotate 2nd diagonal:")
	print_matrix(m4)
	print()

	# Spin 90 degree clockwise
	m5 = [
		[ 1, 2, 3 ],
		[ 4, 5, 6 ],
		[ 7, 8, 9 ],
	]
	print("Before spinning 90 degree clockwise:")
	print_matrix(m5)
	spin_90degree_clockwise(m5)
	print("After  spinning 90 degree clockwise:")
	print_matrix(m5)
	print()

	print("Done")
