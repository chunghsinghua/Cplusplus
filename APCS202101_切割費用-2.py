
# sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\Q_3_5_5.in")
n,l=map(int ,input().split())
data = [[int(x) for x in input().split() ] for _ in range(n)]
data.sort(key=lambda x:x[0])
data.append([l,0])
data=[[0,0]]+data
le=[-1]*(n+2)
for i in range(1,n+1):
    le[i]=i-1
ri=[-1]*(n+2)
for i in range(1,n+1):
    ri[i]=i+1
seq=[0]*n
for i in range(1,n+1):
    seq[data[i][1]-1]=i
tot = 0
for p in seq[::-1]:
    left,right = le[p], ri[p]
    tot+=data[right][0]-data[left][0]
    le[right]=left
    ri[left]=right
    
print(tot)
