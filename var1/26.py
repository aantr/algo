import sys
sys.stdin = open('26-59.txt')

n = int(input())
maxn = 1000005
a=[[] for _ in range(maxn)]
for i in range(n):
	r, c = map(int, input().split())
	a[r].append(c)

for i in range(maxn - 1, -1, -1):
	a[i].sort()
	k = len(a[i])
	for j in range(k - 1):
		if (a[i][j] == a[i][j + 1] - 3):
			print(i, a[i][j] + 1)
			exit()
