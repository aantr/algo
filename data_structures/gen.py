from random import *

n = randint(5, 7000)
print(n)
print(*[randint(1, 10000) for _ in range(n)])
q = randint(5, 7000)
print(q)
for _ in range(q):
	t = randint(0, 1)
	if t == 1:
		l = randint(1, n - 1)
		r = randint(l + 1, n)
		k = randint(1, n - r + 1)
		print(t, l, r, k)
	else:
		l = randint(1, n)
		r = randint(l, n)
		k = randint(1, 10000)
		print(t, l, r, k)