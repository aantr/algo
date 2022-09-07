s = '''15	15	18	16	20	20	19	19	20	15	17	15	16	19	17	17	16	15	15	19
16	18	19	15	15	16	20	15	15	16	17	20	16	20	18	20	18	18	17	20
20	17	16	19	19	15	18	18	16	17	16	15	17	20	15	15	18	19	20	20
18	17	17	17	15	18	16	15	15	17	19	16	20	19	15	17	16	15	18	18
19	15	18	16	17	19	19	20	15	15	17	20	16	19	16	16	16	15	16	20
17	18	19	15	19	17	17	20	20	16	17	16	18	16	18	19	15	17	18	19
19	16	19	17	18	17	20	16	16	18	20	18	20	18	16	15	17	15	19	16
19	15	19	18	16	17	18	19	19	19	17	20	16	20	15	15	18	19	20	18
17	15	15	16	20	16	17	17	15	18	17	20	18	18	20	19	18	19	16	18
18	15	15	16	16	16	20	19	18	18	17	15	17	18	18	15	15	18	15	16
19	18	20	17	16	18	15	16	18	15	15	17	18	18	15	19	16	18	19	17
15	18	19	15	18	16	18	20	19	20	18	17	17	20	15	20	18	15	18	20
19	19	18	19	18	18	18	19	17	19	19	20	16	19	19	20	16	19	17	20
20	18	18	19	15	18	18	15	15	17	17	19	19	15	16	17	18	15	18	16
16	16	16	16	19	19	18	15	17	16	17	15	17	17	15	17	19	19	19	19
15	16	16	19	17	19	18	16	16	17	17	16	16	18	19	19	17	19	18	17
16	20	18	16	20	18	16	16	15	20	17	20	15	15	16	20	20	17	18	20
17	20	20	18	18	15	19	16	17	19	18	15	16	17	17	15	16	20	20	15
16	16	20	16	18	18	16	16	19	19	15	17	16	16	18	19	16	16	16	19
19	15	17	18	19	19	17	19	16	18	17	17	16	17	19	17	15	17	17	18'''

inf = 1e18
s = [list(map(int, i.split())) for i in s.split('\n')]
n = len(s)
dp = [[[inf, -inf] for _ in range(n + 1)] for i in range(n + 1)]
dp[1][0] = [0, 0]
for i in range(n):
	for j in range(n):
		if j == 6 and 3 <= i <= 14:
			dp[i + 1][j + 1][0] = dp[i][j + 1][0] + s[i][j]
			dp[i + 1][j + 1][1] = dp[i][j + 1][1] + s[i][j]
		elif i == 17 and 11 <= j <= 16:
			dp[i + 1][j + 1][0] = dp[i + 1][j][0] + s[i][j]
			dp[i + 1][j + 1][1] = dp[i + 1][j][1] + s[i][j]
		else:
			dp[i + 1][j + 1][0] = min(dp[i + 1][j][0], dp[i][j + 1][0]) + s[i][j]
			dp[i + 1][j + 1][1] = max(dp[i + 1][j][1], dp[i][j + 1][1]) + s[i][j]
print(dp[n][n][1], dp[n][n][0])