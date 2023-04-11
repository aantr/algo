from itertools import combinations

n, m, k = map(int, input().split())
s = input()
if (m == 1):
	print(s)
	exit()

a = []

for i in combinations(range(1, n), m - 1):
	mn = s[:i[0]]
	for j in range(m - 2):
		mn = min(mn, s[i[j]:i[j + 1]])
	mn = min(mn, s[i[m - 2]:])
	a.append(mn)
a.sort(reverse = 1)

print(a[k - 1])