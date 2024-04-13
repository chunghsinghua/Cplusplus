import sys

sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\P_4_9_5.in")

def fun(len,n,k):
    endline = -1
    for i in range(n):
        if d[i]<=endline:
            continue
        if k<=0:
            return False
        k -= 1
        endline = d[i]+len
    return True

n,k=map(int,input().split())
d=[int(x) for x in input().split()]
d.sort()
len = 0
l = d[-1]-d[0]
jump = l//2
while jump > 0:
    while len+jump<=l and not fun(len+jump,n,k):
        len+=jump
    jump>>=1

print(len+1)
