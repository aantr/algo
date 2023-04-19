from math import *

def lcm(a, b):
	return a // gcd(a, b) * b

n = int(input())
a = list(map(int, input().split()))
LG = 20
st = [[0 for _ in range(n)] for _ in range(LG)]
st_lcm = [[0 for _ in range(n)] for _ in range(LG)]

st[0] = a.copy()
st_lcm[0] = a.copy()
for i in range(1, LG):
	for j in range(n - (1 << i) + 1):
		st[i][j] = gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))])
		st_lcm[i][j] = lcm(st[i - 1][j], st[i - 1][j + (1 << (i - 1))])

def get(table, f, l, r):
	# print(l, r)
	x = r - l
	b = x.bit_length() - 1
	return f(table[b][l], table[b][r - (1 << b)])

mx = 0
for i in range(0, n):
	g = a[i]
	cur = i
	for j in range(31):
		l = cur
		r = n
		if l == r:
			break
		while r - l > 1:
			m = l + r >> 1
			if get(st, gcd, i, m + 1) >= g:
				l = m
			else:
				r = m
		j = l + 1
		# print(i, j)
		G = get(st, gcd, i, j)
		N = get(st_lcm, lcm, i, j)
		cur = r
		g = get(st, gcd, i, j + 1)

		mx = max(mx, N * G)

print(mx)