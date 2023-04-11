from random import *

n = randint(5, 8)

a = list(range(1, n + 1))
shuffle(a)
print(n)
print(*a)
