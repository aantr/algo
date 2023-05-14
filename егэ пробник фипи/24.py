import sys
sys.stdin = open('1_24.txt')

s = input()
n = len(s)

cur = 0
mx = 0
for i in range(n):
	if i and s[i] in 'ABC' and s[i - 1] in 'ABC':
		cur = 0
	cur += 1
	mx = max(mx, cur)
print(mx)