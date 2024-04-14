import os
import sys

def print_grid(grid, R, C):
	for r in range(R):
		for c in range(C):
			print(grid[r][c], end=' ')
		print()

def dfs(grid, visited, row, col, path):
	N = len(grid) # Assume NxN grid
	if row < 0 or row >= N or col < 0 or col >= N or visited[row][col]:
		return # Outside the grid or already visited
	visited[row][col] = True
	path.append(grid[row][col])
	dfs(grid, visited, row - 1, col, path) # North
	dfs(grid, visited, row, col + 1, path) # East
	dfs(grid, visited, row + 1, col, path) # South
	dfs(grid, visited, row, col - 1, path) # West

grid = [ [1,2,3], [4,5,6], [7,8,9] ]
N = len(grid)
print_grid(grid, N, N)
visited = [[False]*N for x in range(N)]
path = []
dfs(grid, visited, 0, 0, path)
print('DFS traversal: ' + str(path))
