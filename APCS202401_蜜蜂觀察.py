m,n,k=map(int,input().split())
dr=(-1,0,1,1,0,-1)
dc=(0,1,1,0,-1,-1)
d=[]
path=[]
for _ in range(m):
    d.append(input())
move=[int(x) for x in input().split()]
i,j=m-1,0
for v in move:
    ni, nj=i+dr[v], j+dc[v]
    if 0<=ni<m and 0<=nj<n:
        i,j=ni,nj
    path.append(d[i][j])
print(''.join(path))
print(len(set(path)))
