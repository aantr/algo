def r(start, end):
	if (end == start):
		return 1
	if (start > end):
		return 0
	return r(start, end - 8) + r(start, end // 2)

print(r(5, 43) * r(43, 102))
