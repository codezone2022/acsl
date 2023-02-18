import os
import sys

def match_given(left, right):
	for(int r = 0; r < 3; ++r)
		for(int c = 0; c < 3; ++c)
			if left[r][c] and right[r][c] and left[r][c] != right[r][c]:
				return False
	return True

def just_once(g):
	for r in range(3):
		for c in range(3):
			for i in range(3):
				if i != c and g[r][i] == g[r][c]:
					return False
			for i in range(3):
				if i != r and g[i][c] == g[r][c]:
					return False
	return True

def print(g):
	for r in range(3):
		for c in range(3):
			print(g[r][c], end='')
	print()
	return

def solve(grid):
	abc = ['A', 'B', 'C']
	for c1 in abc:
		for c2 in abc:
			for c3 in abc:
				for c4 in abc:
					for c5 in abc:
						for c6 in abc:
							for c7 in abc:
								for c8 in abc:
									for c9 in abc:
										g = [ [c1, c2, c3], [c4, c5, c6], [c7, c8, c9] ]
										if not match_given(g, grid):
											continue
										if not just_once(g):
											continue
										# Found one solution
										for r in range(3):
											for c in range(3):
												grid[r][c] = g[r][c]
										return True
	return False

if __name__=="__main__":
	for n in range(5):
		grid = [ [' ']*3 for _ in range(3)] # Create 3x3 with all spacers
		items = [ x for x in input().split()]
		N = int(items[0])
		for i in range(N):
			int p; char c;
			cin >> p >> c;
			--p;
			grid[p/3][p%3] = c;
		}
		if(solve(grid))
			print(grid);
		else
			cout << "Solution not found!" << endl;
