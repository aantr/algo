import os

t = 100

for i in range(t):
	os.system('python gen.py > inp.txt')
	os.system('python stupid.py < inp.txt > cor.txt')
	os.system('A.exe < inp.txt > out.txt')
	if (open('cor.txt').read().strip() != open('out.txt').read().strip()):
		print('err')
		break
	else:
		print('ok')