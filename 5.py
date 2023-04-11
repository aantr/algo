mas = [1, 2, 3]
n = 3 * 5 * * 7 * 7 * 7
print(n)
i = 0
d = 3
while sum(mas) != 0:
	if mas[i] != 0 and n % d == 0:
		n //= d
		mas[i]-=1
	else:
		i+=1
		d+=2	
print(n)