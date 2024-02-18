# import sys
# sys.stdin=open('C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\p_1_1_4.in','r')

idx = 0

def fun():
    global s, idx
    head = tail = -1
    total = 0
    while True:
        if idx >= len(s):
            return total, head, tail
        if s[idx] == 'T':
            t = int(s[idx+1:idx+3])
            if head < 0:
                head = t
            else:
                total += abs(tail-t)
            tail = t
            idx += 3
        elif s[idx] == 'L':
            times = int(s[idx+1])
            idx += 2
            cost,h,e = fun()
            if head < 0 :
                head = h
            else :
                total += abs(h-tail)
            tail = e
            total += cost * times + abs(h-e)*(times-1)
        else :
            idx += 1
            return total, head, tail

s=input()
cost, h, e = fun()
print(cost+abs(10-h))
            
