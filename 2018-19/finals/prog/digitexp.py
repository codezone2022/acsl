import os
import sys

def operand(s):
	if not s or len(s) == 0 or s[0] == '0':
		return sys.maxsize
	return int(s)

if __name__=="__main__":
	M = 10 if len(sys.argv) < 2 else int(sys.argv[1])
	for m in range(M):
		digits = input()
		N = len(digits)
		res = 0
		# 1-operator
		n = 1
		while n < N and N-n > 0:
			str1 = digits[0:n]
			str2 = digits[n:]
			#print(str1 + ' ' + str2)
			num1 = operand(str1)
			num2 = operand(str2)
			if num1 != sys.maxsize and num2 != sys.maxsize:
				if num1 + num2 > 0:
					res += 1
				if num1 - num2 > 0:
					res += 1
				if num1 * num2 > 0:
					res += 1
			n += 1
		# 2-operator
		for i in range(1,N):
			for j in range(1, N):
				if N-i-j <= 0:
					continue
				str1 = digits[0:i]
				str2 = digits[i:i+j]
				str3 = digits[i+j:]
				#print(str1 + ' ' + str2 + ' ' + str3)
				num1 = operand(str1)
				num2 = operand(str2)
				num3 = operand(str3)
				if num1 != sys.maxsize and num2 != sys.maxsize and num3 != sys.maxsize:
					if num1 + num2 - num3 > 0:
						res += 1
					if num1 - num2 + num3 > 0:
						res += 1
					if num1 + num2 * num3 > 0:
						res += 1
					if num1 * num2 + num3 > 0:
						res += 1
					if num1 - num2 * num3 > 0:
						res += 1
					if num1 * num2 - num3 > 0:
						res += 1
		# 3-operator
		for i in range(N):
			for j in range(N):
				for k in range(N):
					if N-i-j-k <= 0:
						continue
					str1 = digits[0:i]
					str2 = digits[i:i+j]
					str3 = digits[i+j:i+j+k]
					str4 = digits[i+j+k:]
					#print(str1 + ' ' + str2 + ' ' + str3 + ' ' + str4)
					num1 = operand(str1)
					num2 = operand(str2)
					num3 = operand(str3)
					num4 = operand(str4)
					if num1 != sys.maxsize and num2 != sys.maxsize and num3 != sys.maxsize and num4 != sys.maxsize:
						if num1 + num2 - num3 * num4 > 0:
							res += 1
						if num1 + num2 * num3 - num4 > 0:
							res += 1
						if num1 * num2 - num3 + num4 > 0:
							res += 1
						if num1 * num2 + num3 - num4 > 0:
							res += 1
						if num1 - num2 + num3 * num4 > 0:
							res += 1
						if num1 - num2 * num3 + num4 > 0:
							res += 1
		print(res)
