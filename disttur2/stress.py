from random import *
import sys
sys.stdout = open('input.txt', 'w')
ans = ''
n = int(input())
a = []
b = []
s = ''
st = [1, 1]
cur = 1
for i in range(n):
	# print(a, b)
	act = randint(1, 8)
	if act==1 and st[0]:
		s+='a'
		a.append(cur)
		cur += 1
	if act==2 and st[1]:
		s+='b'
		b.append(cur)
		cur += 1
	if a and act == 3:
		s+='A'
		ans += str(a.pop(0)%10)
	if b and act == 4:
		s+='B'
		ans += str(b.pop(0)%10)
	if st[0] and st[1] and act == 5:
		s+='>'
		b.extend(a[::-1])
		a = []
		st[0]^=1
	if st[1] and st[0] and act == 6:
		s+=']'
		a.extend(b[::-1])
		b = []
		st[1]^=1
	if st[0] == 0 and act == 7:
		s+='<'
		st[0]^=1
		k = len(b)//2
		if not k:
			continue
		a.extend(b[-k:][::-1])
		b = b[:-k]
	if st[1] == 0 and act == 8:
		s+='['
		st[1]^=1
		k = len(a)//2
		if not k:
			continue
		b.extend(a[-k:][::-1])
		a = a[:-k]
print('\n')
print(s)
print('\n')
print(ans)