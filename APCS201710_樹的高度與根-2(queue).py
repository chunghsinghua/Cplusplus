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
    if deg[i]==0:
        que.put(i)

root = p[1:].index(0)+1
print(root)

while not que.empty():
    v = que.get()
    if v == root:
        break
    parent = p[v]
    h[parent]=max(h[v]+1,h[parent])
    deg[parent]-=1
    if deg[parent]==0:
        que.put(parent)
print(sum(h))
