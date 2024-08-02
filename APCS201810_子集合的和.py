import sys

# sys.stdin = open("C:\\Users\\ChungHsingHua\\Documents\\c-program\\kevin\\q_1_8_5.in")

def fun(s, idx):
    global mx
    if idx >= n:
        if s <= p:
            mx = max(mx,s)
        return
    fun(s,idx+1)
    fun(s+arry[idx],idx+1)
    
mx = 0
n,p = map(int,input().split())
arry = [int(x) for x in input().split()]
fun(0,0)
print(mx)
