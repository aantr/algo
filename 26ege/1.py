# https://kompege.ru/variant?kim=25023734

import sys
sys.stdin = open('input.txt')

k, n = int(input()), int(input())

N = k + 1
tree = [0 for _ in range(N)]

def update(pos, val):
	pos += 1
	i = pos
	while i < N:
		tree[i] += val
		i += i & -i

def get_first():
	pos = 0
	for i in range(20, -1, -1):
		if ((1 << i) | pos) < N and tree[(1 << i) | pos] == 0:
			pos |= 1 << i
	return pos

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
s = k
for i in range(2 * n):
	if act[i][1] == 0:
		if s == 0:
			continue
		j = get_first()
		place[act[i][2]] = j
		update(j, -1)
		s -= 1
		ans += 1
		last = j + 1
	else:
		if place[act[i][2]] == -1:
			continue
		update(place[act[i][2]], 1)
		s += 1
print(ans, last)