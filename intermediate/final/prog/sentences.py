import os
import sys

def getWord(words, index):
	res = words[index]
	index += 1
	index %= len(words)
	return res,index

def cap(needCap, word):
	if needCap:
		needCap = False
		word = word[0:1].upper() + word[1:]
	return needCap,word

if __name__=="__main__":
	K = int(input())
	Ns = []
	Cs = []
	Vs = []
	Js = []
	Bs = []
	Ps = []
	Ni = 0
	Ci = 0
	Vi = 0
	Ji = 0
	Bi = 0
	Pi = 0
	for k in range(K):
		ins = [x for x in input().split()]
		part = ins[0]
		if part == 'N':
			Ns = ins[1:]
		elif part == 'C':
			Cs = ins[1:]
		elif part == 'V':
			Vs = ins[1:]
		elif part == 'J':
			Js = ins[1:]
		elif part == 'B':
			Bs = ins[1:]
		elif part == 'P':
			Ps = ins[1:]
	sentences = [x for x in input().split()]
	for i in range(len(sentences)):
		beg = ''
		mid = ''
		end = ''
		needCapital = True
		ch1 = sentences[i][0]
		if ch1 == 'D':
			end = "."
		elif ch1 == 'I':
			end = "."
		elif ch1 == 'Q':
			beg = "What "
			end = "?"
			needCapital = False
		elif ch1 == 'E':
			end = "!"
		for j in range(1,len(sentences[i])):
			cur = ''
			nex = ''
			ch2 = sentences[i][j]
			if ch2 == 'T':
				cur = "the"
				needCapital,cur = cap(needCapital, cur)
				mid += cur
			elif ch2 == 'A':
				ch3 = sentences[i][j+1]
				if ch3 == 'N':
					nex = Ns[Ni]
				elif ch3 == 'C':
					nex = Cs[Ci]
				elif ch3 == 'V':
					nex = Vs[Vi]
				elif ch3 == 'J':
					nex = Js[Ji]
				elif ch3 == 'B':
					nex = Bs[Bi]
				elif ch3 == 'P':
					nex = Ps[Pi]
				ch4 = nex[0]
				if ch4 == 'a':
					cur = "an"
				elif ch4 == 'e':
					cur = "an"
				elif ch4 == 'i':
					cur = "an"
				elif ch4 == 'o':
					cur = "an"
				elif ch4 == 'u':
					cur = "an"
				else:
					cur = "a"
				needCapital,cur = cap(needCapital, cur)
				mid += cur
			elif ch2 == 'N':
				cur,Ni = getWord(Ns,Ni)
				needCapital,cur = cap(needCapital, cur)
				mid += cur
			elif ch2 == 'C':
				cur,Ci = getWord(Cs,Ci)
				needCapital,cur = cap(needCapital, cur)
				mid += cur
			elif ch2 == 'V':
				cur,Vi = getWord(Vs,Vi);
				needCapital,cur = cap(needCapital, cur)
				mid += cur
			elif ch2 == 'J':
				cur,Ji = getWord(Js,Ji);
				needCapital,cur = cap(needCapital, cur)
				mid += cur
			elif ch2 == 'B':
				cur,Bi = getWord(Bs,Bi);
				needCapital,cur = cap(needCapital, cur)
				mid += cur
			elif ch2 == 'P':
				cur,Pi = getWord(Ps,Pi);
				needCapital,cur = cap(needCapital, cur)
				mid += cur
			if j < len(sentences[i])-1:
				mid += ' '
		print(beg + mid + end, end = '')
		if i < len(sentences)-1:
			print(' ', end = '')
	print()
