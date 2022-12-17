m, n, k = map(int, input().split())
monster = [[int(x) for x in input().split()] for type in range(k)]

mat = [[0 for j in range(n)]for i in range(m)]

while len(monster) > 0:
    temp = []
    for s in monster:
        if mat[s[0]][s[1]]:
            mat[s[0]][s[1]] = -1
        else:
            temp.append(s)

    monster, temp = temp, monster

    for i in range(m):
        for j in range(n):
            if mat[i][j] == -1:
                mat[i][j] = 0
    temp = []

    for s in monster:
        mat[s[0]][s[1]] = 1
        s[0] += s[2]
        s[1] += s[3]
        if (0 <= s[0] < m) and (0 <= s[1] < n):
            temp.append(s)
    monster, temp = temp, monster

print(sum(mat[i][j] for i in range(m) for j in range(n)))
