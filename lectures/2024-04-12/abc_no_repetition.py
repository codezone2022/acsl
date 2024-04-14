import os
import sys

def backtrack(alphabet, N, output):
	if len(output) == N:
		print(''.join(output)) # Convert lists to strings
		return
	for letter in alphabet: # Construct candidates
		if letter in output: ###
			continue         ###
		new_output = output[:] # Preserve progress
		new_output.append(letter)
		backtrack(alphabet, N, new_output)
		# After return from the above function backtrack to the preserved 'output'
	return

print('Permutations of 3-letter strings with alphabet "ABC" no repetitions')
# Python strings like Java are immutable. Operate with lists instead.
backtrack(['A','B','C'], 3, [])

print('Permutations of 3-letter strings with alphabet "ABCD" no repetitions')
# Python strings like Java are immutable. Operate with lists instead.
backtrack(['A','B','C','D'], 3, [])

print('Permutations of 3-letter strings with alphabet "ABCDE" no repetitions')
# Python strings like Java are immutable. Operate with lists instead.
backtrack(['A','B','C','D','E'], 3, [])
