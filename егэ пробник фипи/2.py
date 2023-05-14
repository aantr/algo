from itertools import *

for x, y, z, w in product([0, 1], repeat = 4):
	v = (x or not y) and not (y == z) and not w
	if v:
		print(x, y, z, w)