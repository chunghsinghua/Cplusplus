r, c, k, m = map(int, input().split())
r += 2
c += 2
mat = [[] for _ in range(r)]
mat[0] = mat[r-1] = [-1 for _ in range(c)]
for i in range(1, r-1):
    mat[i] = [-1]+[int(x) for x in input().split()]+[-1]
temp = [[0]*c for _ in range(r)]

di = [-1, 0, 1, 0]
dj = [0, 1, 0, -1]
for day in range(m):
    for i in range(r):
        for j in range(c):
            temp[i][j] = mat[i][j]
            if mat[i][j] >= 0:
                for dir in range(4):
                    ni = i+di[dir]
                    nj = j+dj[dir]
                    if mat[ni][nj] >= 0:
                        temp[i][j] -= mat[i][j]//k
                        temp[i][j] += mat[ni][nj]//k

    mat, temp = temp, mat

print(min(mat[i][j] for i in range(r) for j in range(c) if mat[i][j] >= 0))
print(max(mat[i][j] for i in range(r) for j in range(c)))
