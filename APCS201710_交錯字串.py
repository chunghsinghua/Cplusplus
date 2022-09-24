k = int(input())
s = input()
trans = []
for i in s:
    if i.isupper():
        trans.append(1)
    else:
        trans.append(0)

statis = []
cnt = 1
for i in range(1, len(trans)):
    if trans[i] == trans[i-1]:
        cnt += 1
    else:
        statis.append(cnt)
        cnt = 1
statis.append(cnt)

le = 0
ans = 0
leng = len(statis)

while le < leng:
    while le < leng and statis[le] != k:
        le += 1
    if le >= leng:
        break
    ri = le+1
    while ri < leng and statis[ri] == k:
        ri += 1
    t = (ri-le)*k
    if le-1 >= 0 and statis[le-1] > k:
        t += k
    if ri < leng and statis[ri] > k:
        t += k

    if t > ans:
        ans = t

    le = ri+1

print(ans)
