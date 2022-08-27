n = int(input())
friend = [int(x) for x in input().split()]
visit = [False]*n
group = 0
for i in range(n):
    if not visit[i]:
        visit[i] = True
        p = friend[i]
        while p != i:
            visit[p] = True
            p = friend[p]
        group += 1

print(group)
