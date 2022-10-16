n, m = map(int, input().split())
n += 2
m += 2
mat = [[]for i in range(n)]
mat[0] = mat[n-1] = [-1 for i in range(m)]
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]
for i in range(1, n-1):
    mat[i] = [-1]+[int(x) for x in input().split()]+[-1]
mn = 2000000
for i in range(1, n-1):
    for j in range(1, m-1):
        if mat[i][j] < mn:
            mn = mat[i][j]
            si, sj = i, j
total = 0
while True:
    total += mat[si][sj]
    mat[si][sj] = -1
    mn = 2000000
    ni, nj = si, sj
    for d in range(4):
        i, j = si+dr[d], sj+dc[d]
        if mat[i][j] >= 0 and mat[i][j] < mn:
            mn = mat[i][j]
            ni, nj = i, j
    si, sj = ni, nj
    if mat[si][sj] < 0:
        break

print(total)
