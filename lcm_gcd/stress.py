import os

t = 1
for i in range(t):
	os.system('python gen.py > input.txt')
	break
	os.system('python stupid.py < input.txt > correct.txt')
	os.system('python main.py < input.txt > out.txt')
	v = open('correct.txt').read().strip() == open('out.txt').read().strip()
	if not v:
		print('err')
		break
	else:
		print('ok')