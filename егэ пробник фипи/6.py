import turtle as t

t.right(45)

t.tracer(0)
t.setpos(0, 0)
for i in range(10):
	for j in range(20):
		t.up()
		t.setpos((i * 10, -j * 10))
		t.down()
		t.dot(4)
t.setpos(0, 0)
t.tracer(1)

for i in range(7):
	t.forward(50)
	t.right(45)
	t.forward(100)
	t.right(135)

t.done()