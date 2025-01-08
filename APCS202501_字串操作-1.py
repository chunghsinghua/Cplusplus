# import sys
# from pathlib import Path
# sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\q_1_8_5.in")

s = list(input())
slen = len(s)
k=int(input())
for _ in range(k):
    op = int(input())
    if op==0:
        for i in range(1,slen,2):
            s[i],s[i-1]=s[i-1],s[i]
    elif op==1:
        for i in range(1,slen,2):
            if s[i]<s[i-1]:
                s[i],s[i-1]=s[i-1],s[i]
    else:
        t = s.copy()
        to = 0
        for i in range(slen//2):
            s[to] = t[i]
            to +=2
        to = 1
        for i in range(slen//2,slen):
            s[to] = t[i]
            to+=2

print(''.join(s))
