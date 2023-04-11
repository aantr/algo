import os

for i in range(100):
	os.system('python gen.py > inp.txt')
	os.system('A_stupid.exe < inp.txt > cor.txt')
	os.system('A.exe < inp.txt > out.txt')

	if (open('out.txt').read().strip() != open('cor.txt').read().strip()):
		print('err')
	else:
		print('ok')