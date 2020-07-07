import random
import pprint
import time

SWITCHES = 10
CLOCKS = 16
INF = 10000000000

# clocks = []

# for i in range(16):
#     direction = random.randint(1,4)

#     if direction == 1: clocks.append(3)
#     elif direction == 2: clocks.append(6)
#     elif direction == 3: clocks.append(9)
#     elif direction == 4: clocks.append(12)

linked = [
    [True] * 3 + [False] * 13,
    [False,False,False,True] * 2 + [False,True] * 2 + [False] * 4,
    [False] * 4 + [True] + [False] * 5 + [True] + [False] * 3 + [True] * 2,
    [True] + [False] * 3 + [True] * 4 + [False] * 8,
    [False] * 6 + [True] * 3 + [False,True] * 2 + [False] * 3,
    [True,False] * 2 + [False] * 10 + [True] * 2,
    [False] * 3 + [True] + [False] * 10 + [True] * 2,
    [False] * 4 + [True] * 2 + [False,True] + [False] * 6 + [True] * 2,
    [False] + [True] * 5 + [False] * 10,
    [False] * 3 + [True] * 3 + [False,False,False,True] * 2 + [False] * 2
]

def areAligned(clocks):
    for clock in clocks:
        if clock != 12:
            return False

    return True

def push(clocks,switch):
    for i in range(len(clocks)):
        if linked[switch][i]:
            clocks[i] = clocks[i] + 3
            if clocks[i] == 15:
                clocks[i] = 3

def solve(clocks, switch):
    if switch == SWITCHES : 
        return 0 if areAligned(clocks) else INF

    result = INF

    for count in range(4):
        result = min(result, count + solve(clocks,switch + 1)) 
        push(clocks,switch)

    return result

start = time.time()

clocks = [12,6,6,6,6,6,12,12,12,12,12,12,12,12,12,12]
print(f"경우의 수 : {solve(clocks,0)}")
print(f"소요 시간 : {time.time()-start}")