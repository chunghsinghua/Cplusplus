n = int(input())
mat = [[0]*101 for _ in range(101)]
for _ in range(n):
    x, y = map(int, input().split())
    mat[x][y] = 1
for r in range(1,101):
    for c in range(1,101):
        mat[r][c] += max(mat[r-1][c], mat[r][c-1])
print(mat[100][100])
