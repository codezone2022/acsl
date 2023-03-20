import os
import sys
import math

#
# Using a list of two items to represent a complex number as [ real, imaginary ]
#

def addComplex(x, y):
	return [x[0]+y[0], x[1]+y[1]]

def mulComplex(x, y):
	return [x[0]*y[0] - x[1]*y[1], x[0]*y[1]+x[1]*y[0]]

def absComplex(x):
	return math.sqrt( x[0]*x[0] + x[1]*x[1] )

def func(z, C):
	return addComplex( mulComplex(z, z), C )

if __name__=="__main__":
	for n in range(5):
		C = [float(x) for x in input().split()]
		z = [0,0]
		esc = False
		for i in range(1,6): # Evaluate func() 5 times or stop when greater than 4
			z = func(z, C)
			if absComplex(z) > 4.0:
				print("ESCAPES {0}".format(i))
				esc = True
				break
		if not esc:
			res = round(absComplex(z) * 1000.0)/1000.0
			print("{:.3f}".format(res))
