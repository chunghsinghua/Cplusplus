k, q, r = map(int, input().split())
s = '0'+input()
a = [['0']*(k+1) for _ in range(q)]
for i in range(q):
    m = [int(x) for x in input().split()]
    for idx, newidx in enumerate(m, 1):
        a[i][newidx] = s[idx]
    s = "".join(a[i])
res = list(zip(*a))
for i in range(1, r+1):
    print("".join(res[i]))
