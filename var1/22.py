for start in range(81, 1000):
  x=start
  s = 0 
  while x > 0: 
    s = s + x % 9 
    x = x // 3 
  if s == 17:
    print(start)
    break