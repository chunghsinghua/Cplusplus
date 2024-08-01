
# sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\Q_3_5_5.in")
n,l=map(int ,input().split())
data = [[int(x) for x in input().split() ] for _ in range(n)]
data.sort(key=lambda x:x[0])
data.append([l,0])
stk=[[0,0]]
tot = 0
for x in data:
    while x[1]<stk[-1][1]:
        tot+=x[0]
        stk.pop()
    tot-=stk[-1][0]
    stk.append(x)
print(tot)
