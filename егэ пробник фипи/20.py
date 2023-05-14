win = [0 for _ in range(1000)]

for i in range(42, 0, -1):
	var = [i + 1, i + 4, i * 3]
	var = [win[i] for i in var]
	if 0 in var:
		win[i] = 1
	else:
		win[i] = 0

for i in range(1, 43):
	print(i, win[i])