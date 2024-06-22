h, w, n = map(int, input().split())
mat = [[0]*w for _ in range(h)]
for _ in range(n):
    r, c, t, x = map(int, input().split())
    for i in range(r-t, r+t+1):
        for j in range(c-t,c+t+1):
            if (0<=i<h and 0<=j<w and (abs(r-i)+abs(c-j))<=t):
                mat[i][j]+=x
for row in mat:
    print(*row)
