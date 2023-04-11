import os

for i in range(100):
	os.system('python gen.py > inp.txt')
	os.system('D.exe < inp.txt > cor.txt')
	os.system('D_smart.exe < inp.txt > out.txt')
	if (open('cor.txt').read().strip() != open('out.txt').read().strip()):
		print('err')
		print(open('inp.txt').read().strip())
		print('corr')
		print(open('cor.txt').read().strip())
		break
	else:
		print('ok')
