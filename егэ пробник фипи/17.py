import sys
sys.stdin = open('1_17.txt')

n = int(input())
a = [int(input()) for x in range(n)]

cnt = 0
mx = 0
x = max(i for i in a if len(str(i)) == 2)
for i in range(n - 1):
	if int(len(str(a[i])) == 2) + int(len(str(a[i + 1])) == 2) == 1 and (a[i] + a[i + 1]) % x == 0:
		cnt += 1
		mx = max(mx, a[i] + a[i + 1])
print(cnt, mx)