import queue

testfile = open("C:/Users/ChungHsingHua/Documents/c-program/kevin/P_3_1_3.in")
testdata = [line.strip() for line in testfile]


def dfs(n):
    if h[n] >= 0:
        return h[n]
    h[n] = 0
    for e in data[n]:
        h[n] = max(h[n], dfs(e)+1)
    return h[n]


n = int(testdata[0])
data = [[] for _ in range(n+1)]
parent = [0]*(n+1)
h = [-1]*(n+1)

for i in range(1, n+1):
    chnum, *children = map(int, testdata[i].split())
    data[i] = children
    for j in children:
        parent[j] = i

for root in range(1, n+1):
    if parent[root] == 0:
        break

dfs(root)
total = sum(h[1::])
print(root)
print(total)
