import os

for i in range(10000):
	os.system('python gen.py > inp.txt')
	os.system('python stupid.py < inp.txt > cor.txt')
	os.system('C.exe < inp.txt > out.txt')

	if (open('cor.txt').read().strip() != open('out.txt').read().strip()):
		print('err')
		break
	else:
		print('ok')
		print(open('inp.txt').read().strip())
