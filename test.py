n = 16 * 10 + 11
mod = 256
res = pow(n, 20000000008, mod)
print(res // 16, res % 16)