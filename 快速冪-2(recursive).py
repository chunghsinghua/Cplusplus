def exp(x, y, p):
    if y == 0:
        return 1
    if y & 1:
        return x*exp(x, y-1, p) % p
    t = exp(x, y//2, p)
    return t*t % p


x, y, p = map(int, input().split())
print(exp(x, y, p))
