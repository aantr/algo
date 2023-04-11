from subprocess import *
import os

iter = 1000
for _ in range(iter):
	os.system('python gen.py > input.txt')
	
	os.system('F.exe < input.txt > out.txt')
	os.system('stupid.exe < input.txt > ans.txt')
	v1 = open('out.txt').read()
	v2 = open('ans.txt').read()
	print(v1, v2)
	if (v1 == v2):
		print('ok')
	else:
		print('error')
		break
