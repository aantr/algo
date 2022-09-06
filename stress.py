from subprocess import *
from random import *

def test(t):
	open('input.txt', 'w').write(t)
	p=Popen('main.exe<input.txt', shell=1, stderr=0)
	p.wait()
	p=Popen('stupid.exe<input.txt', shell=1, stderr=0)
	p.wait()
	ans1 = open('main.out').read().strip()
	ans2 = open('stupid.out').read().strip()

	if ans1!=ans2:
		print('error')
		print(t)
		print(ans1, 'stupid:', ans2)
		return 1
	else:
		print('ok')

for i in range(1000):
	n, m = randint(6, 6), randint(4, 5)
	s=f'{n} {m}\n'
	for i in range(m):
		l=randint(1, n)
		r=randint(l, n)
		s+=f'{l} {r} {randint(0,1)}\n'
	if test(s):
		break