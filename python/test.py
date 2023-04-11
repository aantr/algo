import json

def f(kk):
    k = kk[0]
    for i in range(8):
        if not k[i]:
            k[i] = 0
    return -abs(sum(k[4:]) - sum(k[:4]))

d = json.load(open('reg.json'))
a = []
for i in range(len(d)):
    if not d[i]['automatic']:
        a.append([d[i]['rank'], i + 1])
a = sorted(a, key = f)
for i in a:
    print(i)
# dict_keys(['name', 'location', 'form', 'rank', 'sumRank', 'reliable', 'automatic', 'disqual', 'ad'])
