import sys
from bisect import bisect_left

sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\P_8_7_3.in")

def dfs(v):
    global mx
    cnt[c[v]]+=1
    mx = max(mx,cnt[c[v]])
    for e in adj[v]:
        dfs(e)
    cnt[c[v]]-=1
    

n=int(input())
c= [int(x) for x in input().split()]
adj=[[] for i in range(n)]
cc = [-1]
for i in sorted(c):
    if i!=cc[-1]:
        cc.append(i)
cnt = [0]*len(cc)
for i in range(n):
    c[i]=bisect_left(cc,c[i])
for _ in range(n-1):
    a,b=map(int,input().split())
    adj[a].append(b)

mx = 0
dfs(0)
print(mx)
