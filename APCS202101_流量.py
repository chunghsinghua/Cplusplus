n, m, k = map(int, input().split())
q = [[int(x) for x in input().split()] for i in range(n)]
mn = 1000000000
for case in range(k):
    c = [int(x) for x in input().split()]
    qq = [[0]*m for _ in range(m)]
    for i in range(n):
        for j in range(m):
            qq[c[i]][j] += q[i][j]

    cost = 0
    for i in range(m):
        for j in range(m):
            if i == j:
                cost += qq[i][j]
            else:
                if qq[i][j] <= 1000:
                    cost += qq[i][j]*3
                else:
                    cost += 3000+(qq[i][j]-1000)*2
    mn = min(mn, cost)

print(mn)
