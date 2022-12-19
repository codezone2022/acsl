#!/usr/bin/python3
import sys
import math

def isPrime(n):
	if n == 2:
		return True
	if n < 2 or n % 2 == 0:
		return False
	for i in range(3, int(math.sqrt(n)), 2):
		if n % i == 0:
			return False
	return True

if __name__ == "__main__":
	x = int(input())
	print(isPrime(x))
