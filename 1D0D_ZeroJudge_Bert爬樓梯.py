d = [0]*10001
d[1] = 1
d[2] = 2

for i in range(3, 10001):
    d[i] = (d[i-1]+d[i-2]) % 1000000007

while True:
    try:
        n = int(input())
        print(d[n])
    except:
        break
