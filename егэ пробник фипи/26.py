import sys

sys.stdin = open('1_26.txt')

k, n = int(input()), int(input())

a = []
for i in range(n):
	l, r = map(int, input().split())
	a.append([l, 0, i])
	a.append([r, 1, i])
a.sort()

b = [0 for _ in range(k)]
which = [-1 for _ in range(n)]
last = -1
cnt = 0

for i in range(2 * n):	
	if (a[i][1] == 0):
		if (sum(b) == k):
			continue
		J = -1
		for j in range(n):
			if not b[j]:
				J = j
				break
		assert J != -1
		last = J
		b[J] = 1
		which[a[i][2]] = J
	else:
		if which[a[i][2]] != -1:
			cnt += 1
			b[which[a[i][2]]] = 0

print(cnt, last + 1)
