import os
import sys
import math

N = 10 if len(sys.argv) < 2 else int(sys.argv[1])
for n in range(N):
	cards = [x for x in input().split()]
	values = { 'A': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'T': 10, 'J': 11, 'Q': 12, 'K': 13 }
	piles = []
	for card in cards:
		if len(piles) == 0:
			p = []
			p.append(card)
			piles.append(p)
			continue
		placed = False
		for pile in piles:
			top = pile[len(pile)-1]
			if (values[top[0]] > values[card[0]] or (top[0] == 'A' and card[0] == 'K')) and top[1] != card[1]:
				pile.append(card)
				placed = True
				break
		if not placed:
			p = []
			p.append(card)
			piles.append(p)
	maxSize = 0
	for pile in piles:
		maxSize = max(maxSize, len(pile))
	minSum = sys.maxsize;
	for pile in piles:
		if len(pile) == maxSize:
			sum = 0;
			for card in pile:
				sum += values[card[0]];
			minSum = min(minSum, sum);
	print(minSum)
