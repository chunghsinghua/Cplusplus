import bisect

n = int(input())
p = [tuple(int(x) for x in input().split()) for _ in range(n)]
last = []
p.sort()
for e in p:
    idx = bisect.bisect_right(last, e[1])
    if idx >= len(last):
        last.append(e[1])
    else:
        last[idx] = e[1]
print(len(last))
