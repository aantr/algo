n = int(input())
sy = [0] * n
sn = [0] * n
time = 0
while 1:
	a = input()
	if a == 'HELP':
		break
	a = list(map(int, a.split()))
	ans = input()
	if ans == 'YES':
		for i in a:
			sy[i - 1] += 1
		time += 1
	elif ans == 'NO':
		for i in a:
			sn[i - 1] = 1
for i in range(n):
	if sy[i] == time and sn[i] == 0:
		print(i + 1, end=' ')
print()