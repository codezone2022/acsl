import os
import sys

def dfs(graph, curr, visited):
	if curr in visited or curr not in graph:
		return # already visited or has no adjacency
	visited.add(curr)
	adj = graph[curr]
	for v in adj:
		if v == curr:
			continue # skip self-loop
		dfs(graph, v, visited) # Continue
	return

# An Unconnected Undirected Graph
vertices = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
edges = [ 'AB', 'AD', 'BD', 'CF', 'FG', 'GH', 'GE', 'HE' ]

adjs = {} # Adjacency 'matrix'
for edge in edges:
	depart = edge[0]
	arrive = edge[1]
	if depart not in adjs:
		adjs[depart] = set()
	if arrive not in adjs:
		adjs[arrive] = set()
	adjs[depart].add(arrive) # 2 of such for undirected b/c they are symmetric
	adjs[arrive].add(depart) # 1 of such for directed

visited = set()
dfs(adjs, 'A', visited)
if len(visited) == len(vertices):
	print("Connected")
else:
	print("Not connected")
