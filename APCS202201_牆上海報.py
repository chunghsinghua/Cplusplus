def fun(height):
    wi = 0
    cnt = 0
    for hh in h:
        if hh < height:
            cnt = 0
            continue
        cnt+=1
        if cnt == w[wi]:
            cnt = 0
            wi += 1
        if wi == len(w):
            return True
    return False

n, k = map(int,input().split())
h = [int(x) for x in input().split()]
w = [int(x) for x in input().split()]

best = 0
jump = max(h) // 2
while jump > 0:
    while fun(best + jump):
        best += jump
    jump //= 2

print(best)
