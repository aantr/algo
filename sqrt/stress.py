from os import popen

t = 1
for i in range(t):
	popen(f'python gen.py {i} > input.txt').readlines()
	print('test:', i + 1)
	res1 = popen('K.exe < input.txt').readlines()