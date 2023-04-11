from random import *
from itertools import combinations

n = randint(100, 120)
m = randint(2, 3)
print(n, m, randint(1, len(list(combinations(range(0, n - 1), m - 1)))))
for i in range(n):
	print(chr(ord('a') + randint(0, 2)), end='')