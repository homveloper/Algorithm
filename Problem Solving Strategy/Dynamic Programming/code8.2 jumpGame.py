import random as r
from pprint import pprint
import time

size = r.randint(1,100)
board = [[r.randint(1,9) for i in range(size)] for j in range(size)]

# x,y 위치로 jump 할 수 있는지 판단
def jump(x,y):

    # 기저 사례 : 게임판 밖을 벗어난 경우
    if x >= size or y >= size:
        return False
    
    # 기저 사례 : 마지막 칸에 도착한 경우
    if x == size-1 and y == size-1 :
        return True

    jumpSize = board[x][y]

    return jump(x,y + jumpSize) or jump(x+jumpSize, y)


# 메모이제이션을 적용한 jump
cache = [[-1 for i in range(size)] for j in range(size)]
def jump2(x,y):

    # 기저 사례 : 게임판 밖을 벗어난 경우
    if x >= size or y >= size:
        return False
    
    # 기저 사례 : 마지막 칸에 도착한 경우
    if x == size-1 and y == size-1 :
        return True

    result = cache[x][y]
    if result != -1:
        return result
    
    jumpSize = board[x][y]
    cache[x][y] = jump2(x,y + jumpSize) or jump2(x+jumpSize, y)
    return cache[x][y]

start = time.time()
result = jump2(0,0)
print("memoization jump time : ", time.time()-start)
print("결과 : ", result)

start = time.time()
result = jump(0,0)
print("recursive jump time : ", time.time()-start)
print("결과 : ", jump(0,0))



