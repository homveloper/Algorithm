import time
from pprint import pprint

"""
    (n,r) = (n-1, r-1) + (n-1,r)
    (n,0) = 1
    (n,r) = 1
"""

# 재귀 호출을 이용한 이항 계수 계산


def bino(n, r):
    if r == 0 or n == r:
        return 1

    return bino(n-1, r-1) + bino(n-1, r)


# 메모이제이션을 이용한 이항 계수 계산
cache = [[-1 for i in range(30)] for j in range(30)]

def bino2(n, r):
    if r == 0 or n == r:
        return 1

    if cache[n][r] != -1:
        return cache[n][r]

    cache[n][r] = bino2(n-1, r-1) + bino2(n-1, r)

    return cache[n][r]

n = 28
r = 15

start = time.time()
result = bino(n, r)
print("recursive bino time : ", time.time()-start)
print("결과 : ", result)

start = time.time()
result = bino2(n, r)
print("memoization bino time : ", time.time()-start)
print("결과 : ", result)
