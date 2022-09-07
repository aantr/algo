maxs = 37
inf = 1e9

ans1 = -inf
ans21 = inf
ans22 = -inf
ans3 = inf

def get_moves(x):
	if (x == 1):
		return [1, 1]
	if (x == 2):
		return [1, 1]
	return [x//2 if x % 2 == 0 else x-2, x // 3 if x % 3 == 0 else x - 3]

opt = [[] for _ in range(maxs+1)]
opt[1] = [0]
for i in range(2, maxs + 1):
	v = get_moves(i)
	v = (opt[v[0]] if len(set(opt[v[0]])) == 1 else []) + (opt[v[1]] if len(set(opt[v[1]])) == 1 else [])
	wins = [i + 1 for i in v if i % 2 == 0]
	lose = [i + 1 for i in v if i % 2 == 1]
	if (wins):
		opt[i] = wins
	else:
		opt[i] = lose

for s in range(1, maxs + 1):
	moves = [set([s])]
	for i in range(3):
		new_layer = set()
		for j in moves[-1]:
			new_layer.add(get_moves(j)[0])
			new_layer.add(get_moves(j)[1])

		moves.append(new_layer)

	if (len(moves[1]) > 1 and 1 in moves[1] and 1 in moves[2]):
		ans1 = max(ans1, s)
	if (1 not in moves[1] and 3 in opt[s]):
		ans21 = min(ans21, s)
		ans22 = max(ans22, s)
	if 4 in opt[s] and len(set(opt[s])) > 1:
		ans3 = min(ans3, s)

print(ans1)
print(ans21, ans22)
print(ans3)
