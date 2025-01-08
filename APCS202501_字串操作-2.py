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
        le = s[:slen//2]
        ri = s[slen//2:]
        idx = 0
        for u,v in zip(le,ri):
            s[idx], s[idx+1] = u,v
            idx+=2

print(''.join(s))
