n, m = map(int, input().split())
mat = []
for i in range(n):
    mat.append([int(x) for x in input().split()])
answer = []
for i in range(n):
    for j in range(m):
        x = mat[i][j]
        total = 0
        for s in range(i-x, i+x+1):
            for t in range(j-x, j+x+1):
                if 0 <= s < n and 0 <= t < m and abs(s-i)+abs(t-j) <= x:
                    total += mat[s][t]
        if total % 10 == x:
            answer.append((i, j))
print(len(answer))
for x, y in answer:
    print(x, y)
