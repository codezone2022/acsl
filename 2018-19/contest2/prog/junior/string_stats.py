import os
import sys

diffs = [0]*26
vowels = 0
up = 0
s = input()
l = list(s)
for i in range(len(s)): # case insensitive counting array
	c = s[i]
	if c.isupper():
		diffs[ord(c)-ord('A')] += 1
		if c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U':
			vowels += 1
		up += 1
	elif c.islower():
		diffs[ord(c)-ord('a')] += 1
		if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u':
			vowels += 1
	else: # non-letter
		l[i] = ' '
	cnt = 0
	max_val = 0
s = ''.join(l)
for i in range(26):
	if diffs[i] > 0:
		cnt += 1
	max_val = max(max_val, diffs[i])
print(cnt)
print(vowels)
print(up)
print(max_val)
words = []
tokens = s.split()
for word in tokens:
	if len(words) == 0:
		words.append(word)
		continue
	if len(word) < len(words[len(words)-1]):
		continue
	if len(word) == len(words[len(words)-1]):
		words.append(word)
		continue
	words = []
	words.append(word)
if len(words) == 1:
	print(words[0])
	sys.exit(0)
low_words = []
for word in words:
	low_words.append(word.tolower())
swords = sorted(low_words)
first = swords[0]
for i in range(len(words)):
	if low_words[i] == first:
		print(words[i])
		sys.exit(0)
