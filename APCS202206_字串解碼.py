m, n = map(int, input().split())
e = []
for _ in range(m):
    tmp = input()
    e.append(tmp)

t = list(input())
for ee in e[::-1]:
    s = []
    for et in ee[::-1]:
        if et == '1':
            s.append(t.pop())
        else:
            s = [t.pop()]+s

    if ee.count('1') & 1:
        if n & 1:
            s = s[n//2+1:]+[s[n//2]]+s[:n//2]
        else:
            s = s[n//2:]+s[:n//2]

    t = (s)
print("".join(t))
