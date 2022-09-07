numbers = list(map(int, open('17.txt').readlines()))
n = len(numbers)

def get(x):
	return x % 10 == 9 and x > 0

cnt = 0
mx = 0
for i in range(n - 2):
	if (get(numbers[i]) == 0 and get(numbers[i + 1]) == 1 and get(numbers[i + 2]) == 0):
		mx = max(mx, sum(numbers[i:i + 3]))
		cnt+=1
print(cnt, mx)