
# 조건 : n >= 1
# 기능 : 1~n 까지의 합
def recursiveSum(n):
    if n <= 1 : return n

    return n + recursiveSum(n-1)

