import random as r
from pprint import pprint

N = r.randint(2,10)
taken = [False for i in range(N)]

def setFriends(N):
    
    areFriends = [[False for i in range(N)] for i in range(N)]

    for i in range(N):
        for j in range(N):
            if r.randint(0,4) == 4:
                areFriends[i][j] = True
                areFriends[j][i] = True

    return areFriends

areFriends = setFriends(N)

def countParing(taken):
    firstFree = -1

    for i in range(N):
        if not taken[i]:
            firstFree = i
            break
    
    if(firstFree == -1):
        return 1

    result = 0

    for pairWith in range(firstFree+1,N):

        if not taken[pairWith] and areFriends[firstFree][pairWith]:
            taken[firstFree] = taken[pairWith] = True
            result += countParing(taken)
            taken[firstFree] = taken[pairWith] = False

    return result

pprint(setFriends(5))
print(N)
print(countParing(taken))