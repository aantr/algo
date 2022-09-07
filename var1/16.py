def f (n):
	if (n <= 1):
		return 3
	return f(n - 1) - f(n - 2) + 3 *n if n % 2 == 0 else f(n - 2) - f(n - 3) + 2 * n
print(f(40))