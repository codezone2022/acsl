import math
import os
import sys

def addComplex(x, y):
	return [ x[0]+y[0], x[1]+y[1] ]

def mulComplex(x, y):
	return [ x[0]*y[0] - x[1]*y[1], x[0]*y[1]+x[1]*y[0] ]

def absComplex(x):
	return math.sqrt( x[0]*x[0] + x[1]*x[1] )

def func(z, C):
	return addComplex( mulComplex(z, z), C )

for n in range(5):
	C = [float(x) for x in input().split()]
	z = [0.0, 0.0]
	i = 0
	results = {}
	while True:
		i += 1
		z = func(z, C);
		print(z, end=' -> ')
		z = [ round(z[0]*100.0)/100.0, round(z[1]*100.0)/100.0 ];
		print(z)
		# Do we have an escape?
		if absComplex(z) > 4.0:
			print("ESCAPES {0}".format(i))
			break;
		s = "{0:.2f} {1:.2f}".format(z[0],z[1])
		# Do we have a cycle? A repeated value
		if s in results:
			print(i - results[s])
			break;
		results[s] = i
