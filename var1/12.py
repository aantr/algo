mx = 0
for i in range(0, 100):
	for j in range(0, 100):
		if i + j <= 20 and i <= 15 and j <= 15:
			mx = max(mx, i * 7 + j * 6 + (15 - i) * 3 + (10 - j) * 4)
print(mx)