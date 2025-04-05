vec = [int(x) for x in input().split()]


def fun(v):
    global idx
    ret = 0
    for i in range(2+v % 2):
        u = vec[idx]
        idx += 1
        if u > 0:
            ret += abs(u-v)+fun(u)
    return ret


idx = 1
print(fun(vec[0]))
