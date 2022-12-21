import os
import sys

def is_vowel(c):
	if c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U':
		return True
	return False

def remove_double_consonants(s):
	res = ''
	for c in s:
		if len(res) == 0:
			res += c
			continue
		p = res[len(res)-1]
		if not is_vowel(p) and not is_vowel(c) and p == c:
			continue
		res += c
	return res

def remove_vowel(s):
	res = ''
	for c in s:
		if not is_vowel(c):
			res += c
	return res

def remove_like_LR(s1, s2):
	r1 = ''
	r2 = ''
	length = min(len(s1), len(s2));
	for i in range(length):
		if s1[i] == s2[i]:
			continue
		r1 += s1[i]
		r2 += s2[i]
	if length == len(s1):
		for i in range(length, len(s2)):
			r2 += s2[i]
	if length == len(s2):
		for i in range(length, len(s1)):
			r1 += s1[i]
	return r1,r2

def remove_like_RL(s1, s2):
	s1 = s1[::-1] # [::-1] reverse strings directly
	s2 = s2[::-1] # another approach is: ''.join(reversed(list(s)))
	r1,r2 = remove_like_LR(s1, s2)
	r1 = r1[::-1]
	r2 = r2[::-1]
	return r1,r2

for n in range(5):
	one,two = [x for x in input().split()]

	one = remove_double_consonants(one);
	two = remove_double_consonants(two);

	one = remove_vowel(one);
	two = remove_vowel(two);

	one,two = remove_like_LR(one, two);
	one,two = remove_like_RL(one, two);

	if len(one) == len(two):
		if one < two:
			print(one)
		else:
			print(two)
	else:
		if len(one) < len(two):
			print(one)
		else:
			print(two)
