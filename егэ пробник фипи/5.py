for n in range(5, 1000):
	x = n
	if n % 3 == 0:
		x = int(bin(x)[2:] + bin(x)[-3:], 2)
	else:
		x = int(bin(x)[2:] + bin((x % 3) * 2)[2:], 2)
	if x >= 76:
		print(n)
		breakn