import queue

testfile = open("C:/Users/ChungHsingHua/Documents/c-program/kevin/P_3_1_3.in")
indata = [line.strip() for line in testfile]

n = int(indata[0])
data = [[] for _ in range(n+1)]
chnum = [0]*(n+1)
parent = [0]*(n+1)
h = [0]*(n+1)
que = queue.Queue()

for i in range(1, n+1):
    chnum[i], *children = map(int, indata[i].split())
    data[i] = children
    for j in children:
        parent[j] = i
    if chnum[i] == 0:
        que.put(i)

total = 0
while not que.empty():
    v = que.get()
    total += h[v]
    p = parent[v]
    if p == 0:
        root = v
        break
    h[p] = max(h[p], h[v]+1)
    chnum[p] -= 1
    if chnum[p] == 0:
        que.put(p)

print(root)
print(total)
