import sys

sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\P_3_4_5.in")

n=int(input())
h = [1e7+10]+[int(x) for x in input().split()]
stk=[0]
tot = 0
for i in range(1,n+1):
    while h[stk[-1]]<=h[i]:
        stk.pop()
    tot += i-stk[-1]
    stk.append(i)
print(tot)
