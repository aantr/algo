from itertools import *

cnt = 0
n = 10
for w in product('abcde', repeat = n):
	if w[0] in 'ae':
		continue
	ok = 1
	for i in range(n - 1):
		if w[i] != 'e' and w[i + 1] <= w[i] or w[i] == w[i + 1]:
			ok = 0
			break
	for i in range(n - 4):
		if w[i : i + 5] == w[i : i + 5][::-1]:
			ok = 0
			break
	if not ok:
		continue

	cnt += 1
print(cnt)