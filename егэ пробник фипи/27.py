import sys

sys.stdin = open('1_27_B.txt')

k, n = int(input()), int(input())
a = []
for i in range(n):
	a.append(int(input()))


mx = -1e9
ans = 0
for i in range(n):
	if i - k >= 0:
		mx = max(mx, a[i - k])
	ans = max(ans, a[i] + mx)

print(ans)