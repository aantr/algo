pos = 2_102_530_993_803 - 1
cur = 25

while 1:
	if pos % 3 != 2:
		print(chr(ord('A') + cur))
		break
	else:
		pos = pos // 3
		cur -= 1
