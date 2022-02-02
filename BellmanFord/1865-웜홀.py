'''
벨만 포드

한 노드에서 다른 노드까지의 최단 거리를 구하는 알고리즘으로, 음의 가중치를 
가진 간선일때도 구할 수 있다.

특징
- Vertex - 1 번의 매 단계마다 모든 간선을 전부 확인하면서 모든 노드간의 최단 거리를 구해나간다.
- 음수 간선이 있어도 최적의 해를 찾을 수 있다.
- 시간 복잡도 O(VE)

방법
1. 출발 노드를 설정
2. 최단 거리 테이블을 초기화
3. 모든 간선 E개를 하나씩 확인한다.
4. 각 간선을 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블을 갱신
5. 3~4번 과정을 Vertex-1번 반복한다.

참고
음수 간선의 순환이 발생하는지 확인하고 싶다면, 3~4번 과정을 한번더 수행하여
최단 거리 테이블이 갱신되는지 확인한다. 만약 갱신된다면, 음수 간선의 순환이 존재한다.
'''

from sys import stdin
import sys
input = stdin.readline

T = int(input())
INF = sys.maxsize

'''
N : 정점 개수
M : 양방향 + 가중치 간선 개수
W : 단방향 - 가중치 간선 개수
'''

# 반환값은 음수 순환이 존재하는지 여부
def bellman_ford(N : int, Edge : list, start : int) -> bool:
    # 1~2. 출발 노드 설정 및 최단 거리 테이블 초기화
    D = [INF] * N
    D[start] = 0

    # 3. Vertex-1번 반복하면서 각 정점간의 비용 계산
    for n in range(N):
        # 4. 모든 간선을 거쳐 비용 계산
        for [current, next, distance] in Edge:
            if  D[current] + distance < D[next]:
                D[next] = D[current] + distance

                # 5. 마지막에 값이 갱신된다면, 음수 순환이 발생
                if n == N-1:
                    return True

    return False

for _ in range(T):
    Edge = []
    N,M,W = map(int, input().split())

    for m in range(M):
        S,E,T = map(int ,input().split());  S-=1;E-=1;
        Edge.append([S,E,T])
        Edge.append([E,S,T])

    for w in range(W):
        S,E,T = map(int, input().split());   S-=1;E-=1;
        Edge.append([S,E,-T])

    print("YES" if bellman_ford(N,Edge,0) else "NO")

'''
3
4 4 1
1 4 1
4 1 1
3 1 1
3 2 1
2 3 2
4 3 1
1 2 1
2 1 1
3 4 1
4 3 2
6 4 4
1 2 1
2 3 1
4 5 1
5 6 1
3 2 1
2 1 1
6 5 1
5 4 2
'''

'''
1 ->(1) <-(-1)  2 ->(1) <-(-1)  3



4  ->(1)<-(-2)   5   ->(1) <-(-1)     6

'''