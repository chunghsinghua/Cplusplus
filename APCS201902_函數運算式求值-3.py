def f(x):
    return 2*x-3

def g(x, y):
    return 2*x+y-7

def h(x, y, z):
    return 3*x-2*y+z

stack = []
pop = stack.pop
append = stack.append
for s in reversed(input().split()):
    if s == 'f':
        append(f(pop()))
    elif s == 'g':
        append(g(pop(), pop()))
    elif s == 'h':
        append(h(pop(), pop(), pop()))
    else:
        append(int(s))

print(stack[0])
