maxn = int(600000)

r = [0 for _ in range(maxn)]
mx = [0 for _ in range(maxn)]
for i in range(2, maxn):
	for j in range(2 * i, maxn, i):
		r[j] += i
		mx[j] = max(mx[j], i)
cnt = 0
for i in range(520000, maxn):
	if (r[i] and str(r[i]) == str(r[i])[::-1]):
		print(i, mx[i])
		cnt+=1
		if cnt >= 5:
			break