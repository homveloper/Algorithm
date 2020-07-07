"""
    1 + 2 + 3 + 4 + 5 +...+ n을
    빠르게 계산하는 fastSum

    분할정복을 이용하여
    fastSum(n) 
    = ( 1 + 2 + 3 + 4 + n/2 ) + ((n/2 + 1) + ... + n)
    = fastSum(n/2) + ((n/2 + 1) + ... + n)
    = fastSum(n/2) + (n/2 + 1) + (n/2 + 2) + (n/2 + 3) + ... + (n/2 + n/2)
    = fastSum(n/2) + n/2 * n/2 + (1+2+3+...+n/2)
    = n^2 / 4 + 2*fastSum(n/2)
"""

import time

def fastSum(n):
    if n == 1 : return 1
    if n % 2 == 1 : return fastSum(n-1) + n
    return 2 * fastSum(n/2) + (n**2)/4

def iterableSum(n):
    sum = 0
    for i in range(1,n+1):
        sum = sum + i
    
    return sum

if __name__ == "__main__" : 

    n = 10000000

    start = time.time()
    print("fastSum : ",fastSum(n))
    print("소요시간 : ",time.time()-start)

    start = time.time()
    print("iterableSum : ",iterableSum(n))
    print("소요시간 : ",time.time()-start)

    start = time.time()
    print("sum : ",sum([i for i in range(1,n+1)]))
    print("소요시간 : ",time.time()-start)
