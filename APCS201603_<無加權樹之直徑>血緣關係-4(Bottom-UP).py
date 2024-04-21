import sys

sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\P_8_14_5.in")

n=int(input())
h=[0]*n
p=[-1]*n
deg=[0]*n
for _ in range(n-1):
    a,b=map(int,input().split())
    p[b]=a
    deg[a]+=1
        
pos = [x for x in range(n) if deg[x]==0]
head = 0
while head < len(pos):
    v = pos[head]
    head += 1
    parent = p[v]
    if parent == -1:
        break
    deg[parent]-=1
    if deg[parent]==0:
        pos.append(parent)
d = 0
for v in pos[:-1]:
    parent = p[v]
    d = max(d,h[parent]+h[v]+1)
    h[parent] = max(h[parent],h[v]+1)
print(d)
    
