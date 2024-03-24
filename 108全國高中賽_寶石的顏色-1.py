import sys

sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\P_8_7_2.in")

def dfs(v,col):
    num = 0
    for e in adj[v]:
        num = max(num,dfs(e,col))
    num+=(c[v]==col)
    return num    

n=int(input())
c= [int(x) for x in input().split()]
cc = [-1]
for i in sorted(c):
    if(i!=cc[-1]):
        cc.append(i)
adj=[[] for i in range(n)]
for _ in range(n-1):
    a,b=map(int,input().split())
    adj[a].append(b)

mx = 0
for col in cc:
    mx = max(mx,dfs(0,col))
print(mx)
