import queue

testfile = open("C:/Users/ChungHsingHua/Documents/c-program/kevin/P_3_1_4.in")
testdata = [line.strip() for line in testfile]


def dfs(n):
    for e in data[n]:
        dfs(e)
        h[n] = max(h[e]+1, h[n])


n = int(testdata[0])
data = [[] for _ in range(n+1)]
parent = [0]*(n+1)
h = [0]*(n+1)

for i in range(1, n+1):
    chnum, *children = map(int, testdata[i].split())
    data[i] = children
    for j in children:
        parent[j] = i

for root in range(1, n+1):
    if parent[root] == 0:
        break

dfs(root)
total = sum(h)
print(root)
print(total)
