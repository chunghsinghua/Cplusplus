m,n,k=map(int,input().split())
monsters=[[int(x) for x in input().split()]for times in range(k)]

bomb = set()
while len(monsters)>0:
    explode = set() 
    t=[]
    for monster in monsters:
        if (monster[0],monster[1]) in bomb:
           explode.add((monster[0],monster[1]))
        else:
            t.append(monster)
    
    bomb=bomb-explode
    print(bomb)
    monsters.clear()
    for monster in t:
        bomb.add((monster[0],monster[1]))
        monster[0]+=monster[2]
        monster[1]+=monster[3]
        if 0<=monster[0]<m and 0<=monster[1]<n:
            monsters.append(monster)

print(len(bomb))   
