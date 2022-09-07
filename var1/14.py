x = 64 ** 25 + 4 ** 10 - 16 ** 20 - 32 ** 3
for i in range(100):
	if (x % 4 == 2):
		print(i + 1)
		break
	x //= 4