for i in range(0, 10):
	v = int(f'97968{i}15', 15) + int(f'7{i}233', 15)
	if v % 14 == 0:
		print(v // 14, i)