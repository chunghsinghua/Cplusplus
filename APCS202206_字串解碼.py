m, n = map(int, input().split())
e = []
for _ in range(m):
    temp = input()
    e.append(temp)

t = input()
for ss in e[::-1]:

    s = ''
    sidx = n-1
    cnt1 = ss.count('1')

    for i in ss[::-1]:
        if i == '0':
            s = t[sidx]+s
            sidx -= 1
        else:
            s += t[sidx]
            sidx -= 1

    if cnt1 % 2:
        if (n % 2):
            s = s[n//2+1:]+s[n//2]+s[:n//2]
        else:
            s = s[n//2:]+s[:n//2]

    t = s

print(s)
