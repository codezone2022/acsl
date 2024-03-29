import sys
import math

def isPrime(num):
	if num < 2:
		return False
	for n in range(2,int(math.sqrt(num))+1):
		if (num // n) * n == num: # divisible check
			return False
	return True

def setMarker(curr, next, players):
	for i in range(len(players)):
		if players[i] == curr:
			players[i] = next
			return
	return

def occupied(curr, next, players):
	for player in players:
		if curr == player:
			continue
		if next == player:
			return True
	return False

if __name__== "__main__":
	for n in range(5):
		nums = [int(x) for x in input().split()]
		opponent = nums[:3]
		players = nums[3:6]
		num_rolls = nums[6]
		rolls = nums[7:]
		for k in range(num_rolls):
			curr = min(players)
			if curr == 52:
				break
			roll = rolls[k]
			next = curr + roll
			#print("curr="+str(curr)+",roll="+str(roll)+",next="+str(next))
			# Check if will land on an occupied location
			if next == opponent[0] or next == opponent[1] or next == opponent[2] or occupied(curr, next, players):
				continue
			# Check if will land on target location 52
			if next == 52:
				setMarker(curr, next, players)
				break
			# Check if will land beyond 52
			if next > 52:
				continue
			# Check if will land on a prime number
			if isPrime(next):
				for i in range(6):
					next += 1
					if next == opponent[0] or next == opponent[1] or next == opponent[2] or occupied(curr, next, players):
						next -= 1
						break
				setMarker(curr, next, players)
				continue
			# Check if will land on perfect square > 4
			if next == 9 or next == 16 or next == 25 or next == 36 or next == 49:
				for i in range(6):
					next -= 1
					if next == opponent[0] or next == opponent[1] or next == opponent[2] or occupied(curr, next, players):
						next += 1
						break
				setMarker(curr, next, players)
				continue
			# Check if one horizontal move followed by one vertical move
			if (curr <  7 and  7 < next) or (curr < 12 and 12 < next) or (curr < 17 and 17 < next) or (curr < 22 and 22 < next) or (curr < 27 and 27 < next) or (curr < 35 and 35 < next) or (curr < 40 and 40 < next) or (curr < 45 and 45 < next) or (curr < 50 and 50 < next):
				while next > curr:
					if (next // roll) * roll == next and next != opponent[0] and next != opponent[1] and next != opponent[2] and not occupied(curr, next, players):
						break
					next -= 1
				setMarker(curr, next, players)
				continue
			setMarker(curr, next, players)
		players.sort()
		if players[0] == 52 and players[1] == 52 and players[2] == 52:
			print("GAME OVER")
		else:
			for player in players:
				if player == 52:
					break
				print(player, end = ' ')
			print()
