import os
import sys

def toRowCol(r, c, s):
	ri = (s-1) // c
	ci = (s-1) % c
	return [ri, ci]

def toSeqNum(r, c, ri, ci):
	return ri * c + ci + 1

def isValid(r, c, ri, ci):
	return 0 <= ri and ri < r and 0 <= ci and ci < c

def nextPiece(curr):
	ps = ['A','B','C']
	if not curr:
		return 'A'
	return ps[(ord(curr) - ord('A') + 1) % 3]

def isEnd(r, c, s):
	rc = toRowCol(r, c, s)
	return rc[1] == c - 1

def endPole(r, c, begPole, piece):
	rc = toRowCol(r, c, begPole)
	rl = rc[0]
	cl = rc[1]
	rr = 0
	cr = 0
	if piece == 'A':
		rr = rl
		cr = cl + 2
	elif piece == 'B':
		rr = rl + 1
		cr = cl + 1
	elif piece == 'C':
		rr = rl + 2
		cr = cl + 1
	return toSeqNum(r, c, rr, cr) if isValid(r, c, rr, cr) else 0

def canPlace(r, c, blocks, begPole, piece):
	rc = toRowCol(r, c, begPole)
	ri = rc[0]
	ci = rc[1]
	if piece == 'A':
		if not isValid(r,c,ri,ci) or blocks[toSeqNum(r,c,ri,ci)] or not isValid(r,c,ri,ci+1) or blocks[toSeqNum(r,c,ri,ci+1)] or not isValid(r,c,ri,ci+2) or blocks[toSeqNum(r,c,ri,ci+2)]:
			return False
	elif piece == 'B':
		if not isValid(r,c,ri,ci) or blocks[toSeqNum(r,c,ri,ci)] or not isValid(r,c,ri+1,ci) or blocks[toSeqNum(r,c,ri+1,ci)] or not isValid(r,c,ri+1,ci+1) or blocks[toSeqNum(r,c,ri+1,ci+1)]:
			return False
	elif piece == 'C':
		if not isValid(r,c,ri,ci) or blocks[toSeqNum(r,c,ri,ci)] or not isValid(r,c,ri,ci+1) or blocks[toSeqNum(r,c,ri,ci+1)] or not isValid(r,c,ri+1,ci+1) or blocks[toSeqNum(r,c,ri+1,ci+1)] or not isValid(r,c,ri+2,ci+1) or blocks[toSeqNum(r,c,ri+2,ci+1)]:
			return False
	return True

if __name__=="__main__":
	N = 5 if len(sys.argv) < 2 else int(sys.argv[1])
	for i in range(N):
		# Process input data
		nums = [int(x) for x in input().split()]
		r = nums[0]
		c = nums[1]
		s = nums[2]
		n = nums[3]
		blocks = [False]*(r*c+1)
		for j in range(n):
			blocks[nums[j+4]] = True
		# Complete Search - whenever a piece can be placed, move on to the next step
		piece = None
		res = ''
		ep = s
		found = False
		while not found:
			for i in range(3):
				if found:
					break
				piece = nextPiece(piece)
				if canPlace(r, c, blocks, ep, piece):
					res += piece
					ep = endPole(r, c, ep, piece)
					if isEnd(r, c, ep):
						found = True
					else:
						ep += 1
					break
		print(res)
