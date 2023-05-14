s = '12??1*56'

for i in range(10):
	for j in range(10):
		s = f'12{i}{j}156'
		s = int(s)
		if s % 317 == 0:
			print(s, s // 317)

for i in range(10):
	for j in range(10):
		for k in range(10):
			s = f'12{i}{j}1{k}56'
			s = int(s)
			if s % 317 == 0:
				print(s, s // 317)


