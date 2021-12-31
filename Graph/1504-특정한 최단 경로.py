import heapq
from sys import stdin
input = stdin.readline

N,E = map(int ,input().split())
G = [[0 for _ in range(N)] for _ in range(N)]
D = [float('inf') for _ in range(N)]
Q = []

for _ in range(E):
    start, end, distance = map(int, input().split())

    G[start-1][end-1] = distance
    G[end-1][start-1] = distance

V1, V2 = map(lambda x : int(x)-1, input().split())

def reset():
    global D
    D = [float('inf') for _ in range(N)]

def dijkstra(start):
    reset()
    D[start] = 0
    Q = []

    heapq.heappush(Q, (0,start))

    while Q:
        dist, node = heapq.heappop(Q)

        if D[node] < dist:
            continue
        
        for i,d in enumerate(G[node]):
            cost = dist + d
            if cost < D[i]:
                D[i] = cost
                heapq.heappush(Q, (cost, i))


dijkstra(0)
d_v1, d_v2 = D[V1], D[V2]

dijkstra(V1)
d_v1 += D[V2]
d_v2 += D[N-1]

dijkstra(V2)
d_v2 += D[V1]
d_v1 += D[N-1]

result = min(d_v1, d_v2)

print(result if result != float('inf') else -1)