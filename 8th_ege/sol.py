from functools import *

mod = int(1e18)

def correct(mask):
	p = []

	for i in range(4):
		p.append(mask % 5)
		mask //= 5
	for i in range(3):
		if p[i + 1] < 4 and p[i] <= p[i + 1] or p[i] == p[i + 1]:
			return 0
	return 1


@lru_cache(1_000_000_000)
def sol(n, mask):
	# print(n, mask)
	if (n == 1):
		if mask in [1, 2, 3]:
			return 1
		return 0
	if mask // 5 % 5 != 4 and (mask % 5 <= mask // 5 % 5) or mask % 5 == mask // 5 % 5:
		return 0
	if n < 5:
		res = 0
		for M in range(5):
			res += sol(n - 1, mask // 5 + pow(5, 3) * M)
		return res
	res = 0
	for M in range(5):
		p = mask + pow(5, 4) * M
		pal = 1
		s = []
		for i in range(5):
			s.append(p % 5)
			p //= 5
		for i in range(5):
			if s[i] != s[4 - i]:
				pal = 0
				break

		if not pal:
			res += sol(n - 1, mask // 5 + pow(5, 3) * M)
	return res


def mul(a, b):
	assert len(a[0]) == len(b)
	res = [[0 for _ in range(len(b[0]))] for _ in range(len(a))]
	for i in range(len(a)):
		for j in range(len(b[0])):
			for k in range(len(a[0])):
				res[i][j] += a[i][k] * b[k][j]
				res[i][j] %= mod
	return res


def binpow(x, p):
	assert len(x) == len(x[0])
	n = [[0 for _ in range(len(x))] for _ in range(len(x))]
	for i in range(len(x)):
		n[i][i] = 1
	while (p):
		if (p % 2 == 1):
			n = mul(n, x)
		x = mul(x, x)
		p //= 2 

	return n

masks = []
values = []
for i in range(pow(5, 4)):
	if (correct(i)):
		masks.append(i)
		values.append(sol(5, i))
base = []
# print(values)
for i in values:
	base.append([i])

trans = [[0 for _ in range(len(values))] for _ in range(len(values))]

# fill transitions
for i in range(len(masks)):
	mask = masks[i]
	for M in range(5):
		p = mask + pow(5, 4) * M
		pal = 1
		s = []
		for j in range(5):
			s.append(p % 5)
			p //= 5
		for j in range(5):
			if s[j] != s[4 - j]:
				pal = 0
				break

		if not pal:
			j = mask // 5 + pow(5, 3) * M
			# print(s)
			if j in masks:
				j = masks.index(j)
				trans[i][j] = 1
n = 41
res = binpow(trans, n - 5)
res = mul(res, base)
ans = 0
for i in res:
	ans += i[0]
print(ans)

