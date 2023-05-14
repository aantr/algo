t = int(input())
for _ in range(t):
    n = int(input())
    n -= 4
    print(26 + (22 + 2 * (n - 1)) * n // 2)