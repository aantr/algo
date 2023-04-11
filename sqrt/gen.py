from random import *
import sys

seed(int(sys.argv[1]))

n = randint(10, 10000)
q = randint(10, 10000)

a = [randint(100000000, 100000010) for _ in range(n)]

print(n, q)
print(*a)
for _ in range(q):
	t = randint(1, 2)
	if (t == 1):
		l = randint(1, n)
		r = randint(l, n)
		print(t, l, r)
	else:
		print(t, randint(1, n), randint(100000000, 100000010))