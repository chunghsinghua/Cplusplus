import sys,bisect

sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\Q_3_5_5.in")

n=int(input())
h = [-1e8]+[int(x) for x in input().split()]
p = [0]+[int(x) for x in input().split()]
stkh=[-1e8]
stki=[0]
tot = 0
for i in range(1,n+1):
    idx = bisect.bisect_left(stkh,-h[i]-p[i])-1
    tot+=i-stki[idx]-1
    while stkh[-1]>=-h[i]:
        stkh.pop()
        stki.pop()
    stkh.append(-h[i])
    stki.append(i)
print(tot)
