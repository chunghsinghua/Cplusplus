with open("C:/Users/ChungHsingHua/Documents/c-program/kevin/P_3_1_1.in") as testfile:
    testdata = testfile.readlines()


def dfs(n):
    if h[n] >= 0:
        return h[n]
    h[n] = 0
    for e in data[n]:
        h[n] = max(h[n], dfs(e)+1)
    return h[n]


n = int(testdata[0].strip())
data = [[] for _ in range(n+1)]
parent = [0]*(n+1)
h = [-1]*(n+1)

for i in range(1, n+1):
    chnum, *children = map(int, testdata[i].strip().split())
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
