#!/usr/bin/python3
import sys
import math

def digital_root(num):
	res = 0;
	while num >= 10:
		res = res + (num % 10)
		num = num // 10
		if num < 10:
			res = res + num;
			num = res;
			res = 0;
	return num;

if __name__ == "__main__":
	for n in range(0,5):
		s,d,r = [int(x) for x in input().split()]
		total = 0;
		num = s;
		for i in range(0,r):
			total = 0;
			for j in range(0,i+1):
				num = digital_root(num)
				total = total + num
				num = num + d
		print(total)
