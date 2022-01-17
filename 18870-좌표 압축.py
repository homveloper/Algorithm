from sys import stdin
from collections import defaultdict

input = stdin.readline

N = int(input())
L = list(map(int,input().split()))

sorted_L = sorted(L)
idx_hash = defaultdict(int)

previous = -1e10
idx = -1

for i in sorted_L:
    if previous != i:
        idx += 1
        idx_hash[i] = idx
    
    previous = i

print(*map(lambda x : idx_hash[x], L))