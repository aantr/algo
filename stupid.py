n = int(input())

ans = 0

for i in range(1, n + 1):
	v = sum(map(lambda x: int(x) * int(x), list(str(i))))
	if int(v ** 0.5) ** 2 == v:
		ans += 1
print(ans)