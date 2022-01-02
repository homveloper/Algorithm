from sys import stdin
from collections import deque
from itertools import islice

input = stdin.readline
inputs = stdin.readlines

N, D, K, C = map(int,input().split())
L = deque(map(int,inputs()))
l,r,i,result = 0,K,0,0

while i<N:
    shusi = set(islice(L,l,r))
    count = len(shusi)

    if C not in shusi:
        count += 1

    result = max(count,result)

    i += 1
    L.appendleft(L.pop())

print(result)