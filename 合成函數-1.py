import sys
sys.stdin=open('C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\p_1_1_5.in','r')

idx = 0
line = list(input().split())
def fun():
    global idx
    s = line[idx]
    idx+=1
    if s=='f':
        x = fun()
        return 2*x-1
    if s=='g':
        x = fun()
        y = fun()
        return x+2*y-3
    return int(s)

print(fun())
