k, q, r = map(int, input().split())
s = input()
out = []
for _ in range(q):
    mod = [int(x) for x in input().split()]
    t = ['0']*k
    for idx, newidx in enumerate(mod):
        t[newidx-1] = s[idx]
    out.append(t)
    s = "".join(t)
out = list(zip(*out))
for i in range(r):
    print("".join(out[i]))
