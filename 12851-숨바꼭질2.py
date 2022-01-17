from sys import stdin
from collections import deque
from time import time
input = stdin.readline

N, K = map(int, input().split())
INF = 200000

def bfs(start, end) -> int:
    queue = deque([start])
    visited_time = [INF]*100001
    visited_time[start] = 0

    if start == end:
        return 0

    while queue:
        p = queue.popleft()

        if p == end:
            return visited_time[end]

        if 0 <= p-1 <= 100000 and visited_time[p-1] == INF:
            visited_time[p-1] = visited_time[p]+1
            queue.append(p-1)

        if 0 <= p+1 <= 100000 and visited_time[p+1] == INF:
            visited_time[p+1] = visited_time[p]+1
            queue.append(p+1)

        if 0 < p*2<= 100000 and visited_time[p*2] == INF:
            visited_time[p*2] = visited_time[p]+1
            queue.append(p*2)

print(bfs(N,K))