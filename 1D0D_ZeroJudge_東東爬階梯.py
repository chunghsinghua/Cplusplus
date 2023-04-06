d = [0]*110
d[1], d[2] = 1, 2


def fun(n):
    if d[n] > 0:
        return d[n]
    d[n] = fun(n-1)+fun(n-2)
    return d[n]


while True:
    try:
        n = int(input())
        print(fun(n))
    except:
        break
