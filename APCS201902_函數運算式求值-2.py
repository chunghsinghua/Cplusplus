def fun():
    idx = next(s)
    if idx == 'h':
        x = fun()
        y = fun()
        z = fun()
        return 3*x-2*y+z
    elif idx == 'g':
        x = fun()
        y = fun()
        return 2*x+y-7
    elif idx == 'f':
        x = fun()
        return 2*x-3
    else:
        return int(idx)


s = iter(input().split())
print(fun())
