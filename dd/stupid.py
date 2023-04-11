n = int(input())
a = list(map(int, input().split()))
m = int(input())
for i in range(m):
	b = input().split()
	if b[0] == 'u':
		a[int(b[1]) - 1] = int(b[2])
	else:
		l = int(b[1]) - 1
		r = int(b[2])
		k = int(b[3])
		cur = 0
		for i in range(l, r):
			cur += a[i] == 0
			if (cur == k):
				print(i + 1, end = ' ')
				break
		else:
			print(-1, end = ' ')