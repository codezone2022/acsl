import os
import sys

def print_grid(grid, R, C):
	for r in range(R):
		for c in range(C):
			print(grid[r][c], end=' ')
		print()

def print_path(grid, R, C, path):
	for r in range(R):
		for c in range(C):
			if [r,c] in path:
				print('*', end=' ')
			else:
				print(grid[r][c], end=' ')
		print()

# It is also a flood-fill algorithm where typically modify the grid in-place
def dfs(grid, R, C, visited, row, col, path):
	if row < 0 or row >= R or col < 0 or col >= C or visited[row][col]:
		return # Outside the grid or already visited
	if grid[row][col] != 0:
		return # Not a valid cell
	visited[row][col] = True
	path.append([row,col]) # Track the traversal
	dfs(grid, R, C, visited, row-1, col  , path) # North
	dfs(grid, R, C, visited, row-1, col+1, path) # Northeast
	dfs(grid, R, C, visited, row  , col+1, path) # East
	dfs(grid, R, C, visited, row+1, col+1, path) # Southeast
	dfs(grid, R, C, visited, row+1, col  , path) # South
	dfs(grid, R, C, visited, row+1, col-1, path) # Soutwest
	dfs(grid, R, C, visited, row  , col-1, path) # West
	dfs(grid, R, C, visited, row-1, col-1, path) # Northwest

grid = [[1,0,1,0],
		[1,0,1,0],
		[1,1,0,1],
		[1,1,1,0]]
N = len(grid)
print('Maze for 8-way traversal where 1s are walls and 0s to walk:')
print_grid(grid, N, N)

r = 0
c = 0
print('Begin with row={} col={}'.format(r,c))
visited = [[False]*N for x in range(N)]
path = []
dfs(grid, N, N, visited, r, c, path) # DFS Traversal
print_path(grid, N, N, path)

r = 0
c = 1
print('Begin with row={} col={}'.format(r,c))
visited = [[False]*N for x in range(N)]
path = []
dfs(grid, N, N, visited, r, c, path) # DFS Traversal
print_path(grid, N, N, path)
