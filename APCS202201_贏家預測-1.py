n, m = map(int, input().split())
s = [-1]+[int(x) for x in input().split()]
t = [-1]+[int(x) for x in input().split()]
lose = [0]*(n+1)
order = [int(x) for x in input().split()]

while len(order) > 1:
    winteam = []
    loseteam = []
    for i in range(0, len(order), 2):
        if i+1 == len(order):
            winteam.append(order[i])
            break
        p1, p2 = order[i], order[i+1]
        a, b, c, d = s[p1], t[p1], s[p2], t[p2]
        if(a*b >= c*d):
            s[p1] = a+c*d//(2*b)
            t[p1] = b+c*d//(2*a)
            s[p2] = c+c//2
            t[p2] = d+d//2
            winteam.append(p1)
            lose[p2] += 1
            if(lose[p2] < m):
                loseteam.append(p2)
        else:
            s[p2] = c+a*b//(2*d)
            t[p2] = d+a*b//(2*c)
            s[p1] = a+a//2
            t[p1] = b+b//2
            winteam.append(p2)
            lose[p1] += 1
            if(lose[p1] < m):
                loseteam.append(p1)
    order = winteam+loseteam
print(order[0])
