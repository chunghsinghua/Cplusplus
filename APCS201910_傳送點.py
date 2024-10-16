import sys
from queue import Queue
import time

sys.stdin = open(
    "C:\\Users\\chunghsinghua\\Documents\\Programming\\cpp\\Q_7_5_5.in", "r")

st = time.time()
n, p, l, r = map(int, input().split())
d = [int(x) for x in input().split()]
dis = [-1] * n
que = Queue()
que.put(0)
dis[0] = 0
while not que.empty() and dis[p] < 0:
    v = que.get()
    if v-l >= 0 and 0 <= d[v-l] < n and dis[d[v-l]] < 0:
        dis[d[v-l]] = dis[v]+1
        que.put(d[v-l])
    if v+r < n and 0 <= d[v+r] < n and dis[d[v+r]] < 0:
        dis[d[v+r]] = dis[v]+1
        que.put(d[v+r])
print(dis[p])
print(time.time()-st)
