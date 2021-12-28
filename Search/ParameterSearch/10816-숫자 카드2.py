import sys; input = sys.stdin.readline
from bisect import bisect_left, bisect_right

N = int(input())
L = list(map(int, input().split()))
M = int(input())
Q = list(map(int, input().split()))

L.sort()
print(*map(lambda x : bisect_right(L,x)-bisect_left(L,x), Q))