def f(x):
    return 2*x-3

def g(x, y):
    return 2*x+y-7

def h(x, y, z):
    return 3*x-2*y+z

stk = []
pop = stk.pop
append = stk.append
for i in reversed(input().split()):
    if i == 'f':
        append(f(pop()))
    elif i == 'g':
        append(g(pop(), pop()))
    elif i == 'h':
        append(h(pop(), pop(), pop()))
    else:
        append(int(i))

print(stk[0])
