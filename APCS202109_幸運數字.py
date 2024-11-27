import os
import glob

# sys.stdin = open(
#     "C:\\Users\\chunghsinghua\\Documents\\Programming\\cpp\\Q_7_5_5.in", "r")

# fout = open('tt2', 'wt')
# fout.write('this is 1112 test.')
# fout.close()

n = int(input())
vec = [0]+[int(x) for x in input().split()]
idx = [int(x) for x in range(1, n+1)]
psum = [0]*(n+1)
for i in range(1, n+1):
    psum[i] = psum[i-1]+vec[i]
idx.sort(key=lambda x: vec[x], reverse=True)
le, ri = 1, n
while le != ri:
    while idx[-1] > ri or idx[-1] < le:
        idx.pop()
    m = idx.pop()
    lsum = psum[m-1]-psum[le-1]
    rsum = psum[ri]-psum[m]
    if lsum > rsum:
        ri = m-1
    else:
        le = m+1
print(vec[le])
