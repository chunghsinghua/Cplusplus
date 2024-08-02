import sys

sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\Q_7_11_3.in")

def ffind(x):
    if g[x] < 0:
        return x
    g[x] = ffind(g[x])
    return g[x]

def funion(x, y):
    g1 = ffind(x)
    g2 = ffind(y)
    if g[g1] > g[g2]:
        g[g2] += g[g1]
        g[g1] = g2
        return -g[g2]
    else :
        g[g1] += g[g2]
        g[g2] = g1
        return -g[g1]

n,k = map(int ,input().split())
data =[0]+[int(x) for x in input().split()]
g=[0]*(n+1)
for i in range(1,n+1):
    if data[i]:
        g[i] = -1
        if data[i-1]:
            funion(i,i-1)
            
mxtot = mx = -min(g)
mntot = mn = -max([int(x) for x in g if x < 0])

cut = [int(x) for x in input().split()]
for pos in cut:
    data[pos] = 1
    g[pos] = -1
    mn = -1e6
    if data[pos-1]:
        t = funion(pos, pos-1)
        mx = max(t,mx)
        
    if data[pos+1]:
        t = funion(pos, pos+1)
        mx = max(t,mx)
        
    for x in g:
        if x < 0:
            mn = max(mn,x)
    mxtot += mx
    mntot += -mn
    
print(mxtot)
print(mntot)
