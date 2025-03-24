n = int(input())
p = []
dp = [1]*n
dp[0] = 1
for _ in range(n):
    p.append(tuple(int(t) for t in input().split()))
p.sort()
for i in range(0, n):
    for j in range(i+1, n):
        if (p[j][1] >= p[i][1]):
            dp[j] = max(dp[j], dp[i]+1)
print(max(dp))
