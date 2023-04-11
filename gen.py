from random import *
import sys

seed(int(sys.argv[1]))
print(1)
n = randint(3, 100)
print(n)
for i in range(n):
	print(randint(1, n), end = ' ')
print()
for i in range(n):
	print(randint(1, n), end = ' ')
print()