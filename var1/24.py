import sys
sys.stdin = open('24-179.txt')

s = input()
n = len(s)
cnt = [0 for _ in range(26)]
ans = 0
for i in range(n - 4):
	if s[i] == 'C' and s[i + 1] == 'B' and s[i + 3] == 'B' and s[i + 4] == 'C' and \
			(s[i + 2] not in 'ABF'):
		cnt[ord(s[i + 2]) - ord('A')] += 1;
		ans+=1
mx = 0
mx_idx = 0
for i in range(26):
	if (cnt[i] > mx):
		mx = cnt[i]
		mx_idx = i
print(chr(ord('A') + mx_idx), ans)