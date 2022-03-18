x, y, p = map(int, input().split())
ans = 1
for _ in range(y):
    ans = ans*x % p
print(ans)
