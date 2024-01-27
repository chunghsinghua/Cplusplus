import sys
sys.stdin=open('C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\p_1_1_4.in','r')

line=iter(input().split())
def fun():
    s=next(line)
    if s=='f':
        x = fun()
        return 2*x-1
    if s=='g':
        x = fun()
        y = fun()
        return x+2*y-3
    return int(s)

print(fun())
