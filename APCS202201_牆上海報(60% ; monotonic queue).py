n,k=map(int,input().split())
h= [int(x) for x in input().split()]
w= [int(x) for x in input().split()]
deq = []
idx = 0
mx = -1
for i in range(len(h)):
    if len(deq)>0 and deq[idx]<=i-w[0]:
        idx+=1
    while idx<len(deq) and h[deq[-1]]>=h[i]:
        deq.pop()
    deq.append(i);
    if i>=w[0]-1:
        mx = max(mx,h[deq[idx]])
print(mx)
