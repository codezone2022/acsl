import os
import sys
from collections import deque

for n in range(5):
	nums = [int(x) for x in input().split()] # read a series of integers from one line
	total = nums[0]
	cards = nums[1:]

	playerHand = deque();
	playerHand.append(cards[0]); # enq on the right
	playerHand.append(cards[1]); # enq on the right
	playerHand.append(cards[2]); # enq on the right

	for i in range(3,10):
		if i % 2 == 1: # player's turn
			card = playerHand.popleft() # deq on the left
			if card == 9:
				pass
			elif card == 4:
				total -= 10
			elif card == 0:
				if total + 11 <= 99:
					total += 11
				else:
					total += 1
			else:
				total += card
			if total > 99:
				print(str(total) + ", dealer")
				break
			playerHand.append(cards[i])
		else: # dealer's turn
			card = cards[i]
			if card == 9:
				pass
			elif card == 4:
				total -= 10
			elif card == 0:
				if total + 11 <= 99:
					total += 11
				else:
					total += 1
			else:
				total += card
			if total > 99:
				print(str(total) + ", player")
				break
