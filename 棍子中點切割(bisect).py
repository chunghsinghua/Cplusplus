import sys
sys.stdin=open('C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\p_1_3_5.in','r')
import bisect
n,l = map(int,input().split())
p=[0]+[int(x) for x in input().split()]+[l]

def fun(le,ri):
    if le+1>=ri:
        return 0
    m = (p[le]+p[ri])//2
    cost = p[ri]-p[le]
    k = bisect.bisect_left(p,m)
    if p[k-1]-p[le] >= p[ri]-p[k]:
        k-=1
    return cost + fun(le,k) + fun(k,ri)

print(fun(0,n+1))

