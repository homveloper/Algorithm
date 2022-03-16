import sys
from collections import deque, defaultdict
input = sys.stdin.readline

T = int(input())

for t in range(T):
    # N : 노드, K : 간선
    # D : 노드별 시간
    # G : 그래프
    # InD : 위상 차수
    # result : 결과
    # Q : 큐
    N, K = map(int, input().split())
    D = list(map(int, input().split()))
    G = defaultdict(list)
    Q = deque()
    InD = [0 for i in range(N)]
    result = [0 for i in range(N)]

    for _ in range(K):
        s,e = map(int, input().split())
        G[s-1].append(e-1)
        InD[e-1] += 1

    W = int(input())-1

    for i,v in enumerate(InD):
        if v == 0:
            Q.append(i)
    
    for i in range(N):
        d = Q[0]
        Q.popleft()

        for j in G[d]:
            result[j] = max(result[j], result[d] + D[d])

            InD[j] -= 1
            if InD[j] == 0:
                Q.append(j)

    print(result[W] + D[W])