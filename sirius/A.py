import matplotlib.pyplot as plt

def f(t):
	r = (t + 1) ** 0.5
	for i in range(1000):
		r = (t + r) ** 0.5
	return r

x = []
y = []
X = 0
for i in range(100):
	x.append(X)
	y.append(f(X))
	X += 0.01

plt.plot(x, y)
plt.ylabel('some numbers')


plt.show()