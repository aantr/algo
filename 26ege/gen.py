from random import *
import os
os.stdout = open('input.txt', 'w')

n = int(1e6)
k = int(1e6)
print(k)
print(n)

for i in range(n):
	l = randint(1, 1000000 - 1)
	r = randint(l + 1, 1000000)
	print(l, r)