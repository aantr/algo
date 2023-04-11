from random import *

n = randint(5, 10)
a = [randint(1, 100) for _ in range(n)]
q = randint(5, 10)
print(n)
print(*a)
print(q)
for i in range(q):
	print(randint(1, n), randint(1, 100))