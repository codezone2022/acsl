import os
import sys

line = input()
print(len(line)) # line#1
line = input()
sum = 0
for i in range(0,len(line)):
	ch = line[i]
	sum += (ord(ch) - ord('0'))
print(sum) # line#2
line = input()
sum = 0
for i in range(0,len(line),2):
	sum += (ord(line[i]) - ord('0'))
print(sum) # line#3
line = input()
sum = 0
for ch in line:
	if ch == '4':
		sum += 1
print(sum) # line#4
line = input()
length = len(line)
mid = length // 2
if length % 2 == 0:
	mid -= 1
print(line[mid]) # line#5

