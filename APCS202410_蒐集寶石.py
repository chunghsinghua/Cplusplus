import sys
# sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\q_1_8_5.in")

m,n,k,r,c = [int(x) for x in input().split()]
mat = []
mat.append([-1]*(n+2))
for _ in range(m):
    mat.append([-1]+[int(x) for x in input().split()]+[-1])
mat.append([-1]*(n+2))
r+=1
c+=1
d = 0
cnt = score = 0
dr = (0,1,0,-1)
dc = (1,0,-1,0)
while mat[r][c] > 0:
    score += mat[r][c]
    cnt += 1
    mat[r][c] -= 1
    if score % k == 0:
        d = (d+1)%4
    while True:
        nr = r + dr[d]
        nc = c + dc[d]
        if mat[nr][nc]>=0:
            r ,c= nr,nc
            break
        else:
            d = (d+1)%4
print(cnt)
