def fun():
    global idx
    idx += 1
    if s[idx] == 'h':
        x = fun()
        y = fun()
        z = fun()
        return 3*x-2*y+z
    elif s[idx] == 'g':
        x = fun()
        y = fun()
        return 2*x+y-7
    elif s[idx] == 'f':
        x = fun()
        return 2*x-3
    else:
        return int(s[idx])


idx = -1
s = [x for x in input().split()]
print(fun())
