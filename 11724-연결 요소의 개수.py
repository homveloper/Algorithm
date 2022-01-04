from sys import stdin, setrecursionlimit
from collections import defaultdict

setrecursionlimit(10000000)
input = stdin.readline

N, M = map(int, input().split())
G = defaultdict(list)

for _ in range(M):
    s,e = map(lambda x : int(x)-1 , input().split())

    G[s].append(e)
    G[e].append(s)

V = [0] * N
result = 0

def dfs(node):
    V[node] = 1

    for g in G[node]:
        if not V[g]:
            dfs(g)

for i in range(N):
    if not V[i]:
        dfs(i)
        result += 1

print(result)