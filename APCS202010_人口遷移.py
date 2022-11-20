r, c, k, m = map(int, input().split())
r += 2
c += 2
mat = [[] for _ in range(r)]
mat[0] = mat[r-1] = [-1 for _ in range(c)]
temp = [[-1]*c for _ in range(r)]
for i in range(1, r-1):
    mat[i] = [-1]+[int(x) for x in input().split()]+[-1]

di = [-1, 0, 1, 0]
dj = [0, 1, 0, -1]
for day in range(m):
    for i in range(1, r-1):
        for j in range(1, c-1):
            temp[i][j] = mat[i][j]
            if mat[i][j] >= 0:
                for dir in range(4):
                    ni, nj = i+di[dir], j+dj[dir]
                    if mat[ni][nj] >= 0:
                        temp[i][j] -= mat[i][j]//k
                        temp[i][j] += mat[ni][nj]//k
    mat, temp = temp, mat

print(min(mat[i][j] for i in range(r) for j in range(c) if mat[i][j] != -1))
print(max(mat[i][j] for i in range(r) for j in range(c) if mat[i][j] != -1))
