m,n=map(int,input().split())
mat = []
for _ in range(m):
    mat.append([int(x) for x in input().split()])
total = 0
check = True
while(check):
    check = False
    for r in range(m):
        for c in range(n):
            if mat[r][c] == -1 :
                continue
            nr = r+1
            while nr < m and mat[nr][c]==-1:
                nr += 1
            if nr < m and mat[nr][c] == mat[r][c]:
                total += mat[r][c]
                mat[r][c] = mat[nr][c] = -1
                check = True
                continue
            nc = c+1
            while nc < n and mat[r][nc]==-1:
                nc += 1
            if nc < n and mat[r][nc] == mat[r][c]:
                total += mat[r][nc]
                mat[r][c] = mat[r][nc] = -1
                check = True
                continue
print(total)
