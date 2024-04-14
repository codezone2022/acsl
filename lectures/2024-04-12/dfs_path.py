import os
import sys

def dfs(graph, curr, dest, visited):
	if curr in visited:
		return False
	if curr == dest:
		visited.append(curr)
		return True
	visited.append(curr)
	adj = graph[curr]
	for v in adj:
		if v == curr:
			continue # skip self-loop
		if dfs(graph, v, dest, visited):
			return True
	return False

# An Directed Graph
vertices = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
edges = [ 'AB', 'AD', 'CF', 'DA', 'DB', 'EG', 'FC', 'FG', 'GE', 'GF', 'HE', 'HG' ]

adjs = {} # Adjacency 'matrix'

for edge in edges:
	depart = edge[0]
	arrive = edge[1]
	if depart not in adjs:
		adjs[depart] = []
	if arrive not in adjs:
		adjs[arrive] = []
	adjs[depart].append(arrive)

visited = []
if dfs(adjs, 'H', 'C', visited):
	print(visited)
else:
	print('H->C: unreachable')

visited = []
if dfs(adjs, 'C', 'H', visited):
	print(visited)
else:
	print('C->H: unreachable')
