import os

for i in range(100):
	os.system('python gen.py > input.txt')
	os.system('A.exe < input.txt > correct.txt')
	os.system('A1.exe < input.txt > out.txt')
	v = open('correct.txt').read().strip() == open('out.txt').read().strip()
	if v:
		print('ok')
	else:
		print('err')
		break
