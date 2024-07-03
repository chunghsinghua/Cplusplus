# sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\Q_3_5_5.in")

alpha = input()
l = int(input())
s = input()
k = len(alpha)
kl = k**l
check = [False]*kl
p = 0
idx = 0
ref = {ch:i for i,ch in enumerate(alpha)}
# ref = {ch:alpha.index(ch) for ch in alpha}
for i in range(l):
    p = p * k + ref[s[i]]
check[p] = True
for ch in s[l:]:
    p = (p * k + ref[ch]) % kl
    check[p] = True
i = check.index(False)
ret=[]
while i :
    ret.append(alpha[i%k])
    i //= k
if len(ret) < l:
    ret += [alpha[0]]*(l-len(ret))
ret.reverse()
print(''.join(ret))
