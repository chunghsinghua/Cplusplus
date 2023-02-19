k, q, r = map(int, input().split())
s = '0'+input()
ret = []
for _ in range(q):
    p = [0]+[int(x) for x in input().split()]
    tmp = ['0']*(k+1)
    for idx, newidx in enumerate(p):
        tmp[newidx] = s[idx]
    s = "".join(tmp)
    ret.append(s)
ret = list(zip(*ret))
for i in range(1, r+1):
    print("".join(ret[i]))
