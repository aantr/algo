from collections import defaultdict

class F:
	def __init__(self, A, B):
		self.A = A
		self.B = B

def test_case():
	n = int(input())
	changes = []
	vert = [[0, 0, []]]
	vetk = {'main': 0}
	current = 0
	current_vetk = 'main'
	for _ in range(n):
		# print(current_vetk)
		cmd = input().split()
		if cmd[0] == 'add':
			changes.append(F(*cmd[1:]))
			print(f'SUCCESS {current + 1}')
		elif cmd[0] == 'commit':
			if not changes:
				print('FAILURE: no changes')
			else:
				vert.append([current, vert[current][1] + 1, changes.copy()])
				current = len(vert) - 1
				vetk[current_vetk] = current
				changes = []
				print(f'SUCCESS {current + 1}')
		elif cmd[0] == 'reset':
			if changes:
				print('FAILURE: uncommitted changes')
			else:
				current = int(cmd[1]) - 1
				vetk[current_vetk] = current
				print(f'SUCCESS {current + 1}')

		elif cmd[0] == 'checkout':
			if changes:
				print('FAILURE: uncommitted changes')
			else:
				if cmd[1] not in vetk:
					vetk[cmd[1]] = current
					current_vetk = cmd[1]
				else:
					current = vetk[cmd[1]]
					current_vetk = cmd[1]
				print(f'SUCCESS {current + 1}')
		elif cmd[0] == 'rebase':
				if changes:
					print('FAILURE: uncommitted changes')
				else:
					V = vetk[cmd[1]]
					A = current
					B = V
					CURR = []
					OTHER = []
					while vert[A][1] > vert[B][1]:
						CURR += (vert[A][2])
						A = vert[A][0]
					while vert[B][1] > vert[A][1]:
						OTHER += (vert[B][2])
						B = vert[B][0]
					while A != B:
						CURR += (vert[A][2])
						OTHER += (vert[B][2])
						A = vert[A][0]
						B = vert[B][0]
					files1 = defaultdict(set)
					files2 = defaultdict(set)
					try:
						for i in CURR:
							if type(i) != F:
								while 1:
									...
							files1[i.A].add(i.B)

						for i in OTHER:
							files2[i.A].add(i.B)

						ok = 1
						for i in files2.items():
							if len(i[1] - files1[i[0]]) and len(files1[i[0]] - i[1]):
								ok = 0
						if not ok:
							print('FAILURE: conflicts detected')
						else:
							# check
							OTHER = OTHER[::-1]
							for i in range(len(OTHER)):
								vert.append([current, vert[current][1] + 1, OTHER[i]])
								current = len(vert) - 1
								vetk[current_vetk] = current
							print(f'SUCCESS {current + 1}')
					except Exception as w:
						while 1:
							pass



for _ in range(int(input())):
	print(f'Test case {_ + 1}')
	test_case()		