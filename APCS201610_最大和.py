n, m = map(int, input().split())
data = []

for _ in range(n):
    t = [int(x) for x in input().split()]
    data.append(max(t))

s = sum(data)
div = [int(x) for x in data if s % x == 0]

print(s)
if len(div) == 0:
    print(-1)
else:
    print(*div)
