import os
import random
test = 100
for i in range(test):
	os.system(f'python gen.py {random.randint(1, 1000)} > inp.txt')
	os.system('main.exe < inp.txt > cor.txt')
	os.system('main2.exe < inp.txt > out.txt')

	if open('out.txt').read().strip() != open('cor.txt').read().strip():
		print('err')
		break
	else:
		print('ok')
