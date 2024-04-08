import sys, queue

# sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\p_7_2_4.in")

n=int(input())

deg=[0]*(n+1)
p=[0]*(n+1)
h=[0]*(n+1)

que=queue.Queue()
for i in range(1,n+1):
    deg[i],*chs=[int(x) for x in input().split()]
    for ch in chs:
        p[ch]=i

root = p[1:].index(0)+1
print(root)

que=[x for x in range(1,n+1) if deg[x]==0]
head = 0
while head<len(que):
    v = que[head]
    head+=1
    if v == root:
        break
    parent = p[v]
    h[parent]=max(h[v]+1,h[parent])
    deg[parent]-=1
    if deg[parent]==0:
        que.append(parent)
print(sum(h))
