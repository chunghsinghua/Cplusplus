def add(r,c):
    if mat[r][c] != 1 and mat[r][c] != 3:
        r2 = r-1
        while r2>=0 and mat[r2][c] !=4:
            r2-=1
        if r2 >= 0:
            for i in range(r2+1, r):
                mat[i][c]+=1
        
        r2 = r+1
        while r2 < m and mat[r2][c] != 4:
            r2 += 1
        if r2 < m:
            for i in range(r2-1 , r, -1):
                mat[i][c] += 1
    
    if mat[r][c] != 2 and mat[r][c] != 3:
        c2 = c-1
        while c2>=0 and mat[r][c2] !=4:
            c2-=1
        if c2 >= 0:
            for j in range(c2+1, c):
                mat[r][j]+=2
        
        c2 = c+1
        while c2 < n and mat[r][c2] != 4:
            c2 += 1
        if c2 < n:
            for j in range(c2-1 , c, -1):
                mat[r][j] += 2
                
    mat[r][c] = 4
    
def rem(r,c):
    mat[r][c] = 0
    
    r2 = r - 1
    while r2 >=0 and (mat[r2][c]==1 or mat[r2][c]==3):
        mat[r2][c] -= 1
        r2 -= 1
    r2 = r+1
    while r2 < m and (mat[r2][c]==1 or mat[r2][c]==3):
        mat[r2][c] -= 1
        r2 += 1
    c2 = c-1
    while c2 >=0 and (mat[r][c2]==2 or mat[r][c2]==3):
        mat[r][c2] -= 2
        c2 -= 1
    c2 = c+1
    while c2 < n and (mat[r][c2]==2 or mat[r][c2]==3):
        mat[r][c2] -= 2
        c2 += 1
    
m,n,h=map(int,input().split())
mat = [[0]*n for i in range(m)]
mx = cur = 0
for _ in range(h):
    r,c,t=map(int,input().split())
    if t==0:
        add(r,c)
    else:
        rem(r,c)
    
    cur = 0
    for i in range(m):
        cur += n - mat[i].count(0)
    mx = max(mx,cur)

print(mx)
print(cur)
