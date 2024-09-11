import sys
import bisect

sys.stdin = open(
    "C:\\Users\\chunghsinghua\\Documents\\Programming\\cpp\\P_2_15_5.in", "r")

n, m = map(int, input().split())
room = [int(x) for x in input().split()]
for i in range(1, n):
    room[i] += room[i-1]
q = [int(x) for x in input().split()]
idx = 0
for p in q:
    if idx > 0:
        p += room[idx-1]
    if p > room[-1]:
        p -= room[-1]
        idx = 0

    idx = bisect.bisect_left(room, p)
    idx = (idx+1) % n

print(idx)
