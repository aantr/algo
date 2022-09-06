import sys
from math import gcd
sys.stdin = open('27b.txt')

n = int(input())
dp = [[-1e18 for _ in range(35)] for _ in range(n + 1)]
dp[0][0] = 0
for i in range(n):
	a = list(map(int, input().split()))[1:]
	k = len(a)
	for x1 in range(k):
		for x2 in range (x1 + 1 , k):
			v = a[x1]*a[x2]//gcd(a[x1], a[x2])
			for ost in range(35):
				dp[i + 1][ost] = max(dp[i + 1][ost], dp[i][(ost - v + 35) % 35] + v);
ans = 0
for i in range(0, 35):
	if ((i % 5 == 0 or i % 7 == 0) and i % 35 != 0):
		ans = max(ans, dp[n][i])
print(ans)