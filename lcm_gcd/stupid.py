from math import *

n = int(input())
a = list(map(int, input().split()))
mx = 0
I, J = 0, 0
for i in range(n):
	g = 0
	N = 1
	for j in range(i, n):
		G = g = gcd(g, a[j])
		N = N * a[j] // gcd(N, a[j])
		if (N * G > mx):
			mx = N * G
			

print(mx)