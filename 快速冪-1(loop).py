x, y, p = map(int, input().split())
ans = 1
while y:
    if y & 1:
        ans = ans * x % p
    x = x * x % p
    y >>= 1
print(ans)
