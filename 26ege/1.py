import sys
sys.stdin = open('input.txt')

k, n = int(input()), int(input())


t = k
N = 1
while N < t:
	N <<= 1
tree = [0 for _ in range(N * 2)]
for i in range(N - 1, -1, -1):
	tree[i] = tree[i << 1] + tree[i << 1 | 1]

def update(pos, val):
	pos += N
	tree[pos] = val
	pos >>= 1
	while pos > 0:
		tree[pos] = tree[pos << 1] + tree[pos << 1 | 1]
		pos >>= 1

def get_kth(k):
	v = 1
	while v < N:
		if tree[v << 1] >= k:
			v <<= 1
		else:
			k -= tree[v << 1]
			v <<= 1
			v |= 1
	return v - N

act = []
for i in range(n):
	x, y = map(int, input().split())
	act.append([x, 0, i])
	act.append([y, 1, i])
place = [-1 for i in range(n)]
act.sort()
ans, last = 0, 0
for i in range(k):
	update(i, 1)
for i in range(2 * n):
	if act[i][1] == 0:
		if tree[1] == 0:
			continue
		j = get_kth(1)
		place[act[i][2]] = j
		update(j, 0)
		ans += 1
		last = j + 1
	else:
		if place[act[i][2]] == -1:
			continue
		update(place[act[i][2]], 1)
print(ans, last)