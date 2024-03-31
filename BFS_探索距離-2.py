import sys, queue

sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\P_7_1_4.in")

n,m=map(int,input().split())
s = int(input())
adj = [[] for _ in range(n)]
for _ in range(m):
    a,b = map(int,input().split())
    adj[a].append(b)

visit = [False]*n
h=[0]*n
cnt = tot = 0
que = [s]
head = 0
while head < len(que):
    v = que[head]
    head+=1
    visit[v]=True
    for e in adj[v]:
        if visit[e]:
            continue
        visit[e]=True
        cnt += 1
        h[e] = h[v]+1
        tot += h[e]
        que.append(e)
print(cnt)
print(tot)
