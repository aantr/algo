import os

test = 100
for i in range(test):
	os.system('python gen.py > input.txt')
	os.system('A.exe < input.txt > out.txt')
	os.system('stupid.exe < input.txt > corr.txt')
	if (open('out.txt').read().strip() != open('corr.txt').read().strip()):
		print('err, test: ')
		print(open('input.txt').read().strip())
	else:
		print('ok')