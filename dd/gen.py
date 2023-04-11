from random import *

n = randint(5, 10)
print(n)
print(*[randint(0, 2) for _ in range(n)])
m = randint(3, 4)
print(m)
for i in range(m):
	t = randint(0, 1)
	if (t == 1):
		print('u', randint(1, n), randint(0, 3))
	else:
		l = randint(1, n)
		print('s', l, randint(l, n), randint(1, 3))
