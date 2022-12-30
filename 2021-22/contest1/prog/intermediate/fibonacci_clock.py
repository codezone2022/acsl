import os
import sys

for n in range(5): # This loop is not needed on hackerrank.com!
	lower_one, upper_one, two, three, five = [x for x in input().split()]
	hh = 0
	mm = 0
	# red
	if lower_one == 'R':
		hh += 1
	if upper_one == 'R':
		hh += 1
	if two == 'R':
		hh += 2
	if three == 'R':
		hh += 3
	if five == 'R':
		hh += 5
	# green
	if lower_one == 'G':
		mm += 1
	if upper_one == 'G':
		mm += 1
	if two == 'G':
		mm += 2
	if three == 'G':
		mm += 3
	if five == 'G':
		mm += 5
	# blue
	if lower_one == 'B':
		hh += 1
		mm += 1
	if upper_one == 'B':
		hh += 1
		mm += 1;
	if two == 'B':
		hh += 2
		mm += 2
	if three == 'B':
		hh += 3
		mm += 3
	if five == 'B':
		hh += 5
		mm += 5
	mm *= 5
	if mm >= 60:
		hh += (mm//60)
		mm %= 60
	if hh > 11:
		hh %= 12
	print("{0:02}:{1:02}".format(hh,mm))
