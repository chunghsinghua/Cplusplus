n, m = map(int, input().split())
f = [4 for _ in range(n+1)]
t = [1 for _ in range(n+1)]
r = [2 for _ in range(n+1)]
op = [0, 6, 5, 4, 3, 2, 1]
for i in range(m):
    a, b = map(int, input().split())
    if b == -1:
        temp = f[a]
        f[a] = t[a]
        t[a] = op[temp]
    elif b == -2:
        temp = r[a]
        r[a] = t[a]
        t[a] = op[temp]
    else:
        f[a], f[b] = f[b], f[a]
        t[a], t[b] = t[b], t[a]
        r[a], r[b] = r[b], r[a]
ans = [t[x] for x in range(1, n+1)]
print(*ans)
