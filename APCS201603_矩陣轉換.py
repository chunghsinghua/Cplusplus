r, c, m = map(int, input().split())
ret = [[0]*12 for _ in range(12)]
temp = [[0]*12 for _ in range(12)]
for i in range(r):
    col = [int(x) for x in input().split()]
    for j in range(c):
        ret[i][j] = col[j]
op = [int(x) for x in input().split()]

for opi in op[::-1]:
    if opi == 1:
        for row in range(r//2):
            ret[row], ret[r-row-1] = ret[r-row-1], ret[row]
    else:
        for i in range(c):
            for j in range(r):
                temp[i][j]=ret[j][c-1-i]
    
        r,c=c,r
        for i in range(r):
            for j in range(c):
                ret[i][j]=temp[i][j]

print(r,c)
for i in range(r):
    print(*ret[i][:c])
