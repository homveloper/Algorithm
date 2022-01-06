from sys import stdin
import heapq

input = stdin.readline

N = int(input())
H = []

for _ in range(N):
    i = int(input())

    if i == 0:
        if H:
            print(-heapq.heappop(H))
        else:
            print(0)
    else:
        heapq.heappush(H, -i)