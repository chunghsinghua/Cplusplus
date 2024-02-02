# import sys
# sys.stdin=open('C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\p_1_1_4.in','r')

n,k=map(int,input().split())
val=[int(x) for x in input().split()]
d,p=[0]*(n+1),[0]*(n+1)
d[0]=val[0]
for i in range(n):
    d[i]=max(d[i-1],0)+val[i]
for _ in range(k):
    p[0]=max(0,val[0])
    for i in range(1,n):
        p[i]=max(p[i-1]+val[i],d[i-1])
    d,p=p,d
print(max(d))
