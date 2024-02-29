def dp(le,ri):
    if dpn[le][ri]>=0:
        return dpn[le][ri]
    total = sum(a[le:ri+1])
    lsum = 0
    mn = 1e9    
    for i in range(le,ri):
        lsum += a[i]
        mn = min(mn,dp(le,i)+dp(i+1,ri)+abs(total-lsum-lsum))
    dpn[le][ri]= mn
    return dpn[le][ri]
    

n=int(input())
dpn=[[-1]*(n+1) for i in range (n+1)]
a=[0]+[int(x) for x in input().split()]
for i in range (n+1):
    dpn[i][i]=0
print(dp(1,n))
