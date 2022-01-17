'''
무방향 그래프 생성 후
1 ~ N번 까지의 사람들의 케빈 베이컨을
계산하고 최소인 사람을 찾아냄

if 최소값이 여러명이라면 번호가 작은 사람 순으로
'''

from sys import stdin
input = stdin.readline

INF = 1000
N, M = map(int, input().split())
G = [[INF] * (N) for _ in range(N)]

for _ in range(M):
    start, end = map(lambda x : int(x) - 1, input().split())

    G[start][end] = 1
    G[end][start] = 1

for k in range(N):
    G[k][k] = 0
    for s in range(N):
        for e in range(N):
            G[s][e] = min(G[s][e], G[s][k] + G[k][e])

result = INF
result_idx = N
for idx, g in enumerate(G, 1):
    kevin_bacon = sum(filter(lambda x : x != INF, g))

    if kevin_bacon < result:
        result = kevin_bacon
        result_idx = idx

print(result_idx)