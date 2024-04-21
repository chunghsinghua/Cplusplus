import sys

sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\P_8_14_3.in")

d = 0
def dfs(v):
    global d
    for e in adj[v]:
        dfs(e)
        d = max(d,h[v]+h[e]+1)        
        h[v]=max(h[v],h[e]+1)

n=int(input())
h=[0]*n
notroot=[False for _ in range(n)]
adj = [[] for _ in range(n)]
for _ in range(n-1):
    a,b=map(int,input().split())
    adj[a].append(b)
    notroot[b]=True
for root in notroot:
    if root==False:
        break
dfs(root)
print(d)
    
