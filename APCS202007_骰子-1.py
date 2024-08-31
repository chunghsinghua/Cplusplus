#import nump
# sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\q_1_8_5.in")

point = [0,6,5,4,3,2,1]
n,m = map(int ,input().split())
d = [[1,4,2] for _ in range(n+1)]
# top, front, right
for _ in range(m):
    a,b = map(int,input().split())
    if b==-1:
        d[a][1], d[a][0] = d[a][0], 7-d[a][1]
    elif b == -2:
        d[a][2], d[a][0] = d[a][0], 7-d[a][2]
    else:
        d[a],d[b]=d[b],d[a]

ret = [x[0] for x in d[1:n+1]]
print(*ret)
    
