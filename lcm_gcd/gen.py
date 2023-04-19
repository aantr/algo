from random import *

p = [2,3,5,7]
mx = [10, 4, 3, 2]
n = 1000000
print(n)
for i in range(n):
	v = 1
	for j in range(4):
		v *= p[j] ** randint(0, mx[j])
	print(v, end = ' ')