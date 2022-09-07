def p(x):
	return 10 <= x <= 29
def q(x):
	return 13 <= x <= 18
for len in range(70, 0, -1):
	for a in range(100, -100, -1):
		b = a + len
		ok = 1
		for x in range(a - 100, b + 100):
			ok &= ((not (a <= x <= b) or p(x)) or q(x))
		if ok:
			print(len)
			exit(0)
