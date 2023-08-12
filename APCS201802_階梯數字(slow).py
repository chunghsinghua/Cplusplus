import csv

def fun(n):
    k = 9
    while n:
        r = n % 10
        if r > k:
            return 0
        k = r
        n //= 10
    return 1

cnt = 0
testfile = open("C:/Users/ChungHsingHua/Documents/c-program/kevin/P_6_19_1.in")
data = [int(line.strip()) for line in testfile]

n = data[0]
for i in range(1, n+1):
    cnt += fun(i)
print(cnt)
