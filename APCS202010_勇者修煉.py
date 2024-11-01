# sys.stdin = open(
#     "C:\\Users\\chunghsinghua\\Documents\\Programming\\cpp\\Q_7_5_5.in", "r")

m, n = map(int, input().split())
mat = [[int(x) for x in input().split()]for _ in range(m)]
le = [0]*n
ri = [0]*n
dp = [0]*n
for i in range(m):
    le[0] = dp[0]+mat[i][0]
    ri[n-1] = dp[n-1]+mat[i][n-1]
    for j in range(1, n):
        le[j] = max(le[j-1], dp[j])+mat[i][j]
    for j in range(n-2, -1, -1):
        ri[j] = max(ri[j+1], dp[j])+mat[i][j]
    for j in range(n):
        dp[j] = max(le[j], ri[j])
print(max(dp))
