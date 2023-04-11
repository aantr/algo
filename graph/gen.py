from random import *
n = 5000
print(n)
for i in range(n - 1):
	for j in range(n - i - 1):
		print('RB'[randint(0, 1)], end='')
	print()