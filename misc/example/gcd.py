import os
import sys

# Euclid's algorithm for the greatest common divisor via quotient & remainder
def gcd(a, b):
	if a == 0:
		return b
	if b == 0:
		return a
	while b > 0:
		q = a // b
		r = a % b
		a = b
		b = r
	return a

a,b = [int(x) for x in input().split()]
print(gcd(a,b))
