from math import *

def c(n, k):
	return factorial(n) // factorial(k) // factorial(n - k)

for n in range(4, 10000, 4):
	s1 = n * n
	S = 14
	s2 = (n // 4) * (n // 4) * S
	if s1 - 324 * 8 == s2:
		print(n)

print(log(c(16, 8), 2))