'''
플로이드 와샬

(i, j) : i에서 j로 가는 길이 존재

이 문제는 모든 정점에 대해 경로를 계산하여 저장해두고
이를 출력하는 문제이다.
'''

from sys import stdin
input = stdin.readline

N = int(input())
G = [list(map(int,input().split())) for i in range(N)]

for k in range(N):
    for s in range(N):
        for e in range(N):
            if G[s][k] + G[k][e] == 2:
                G[s][e] = 1

for g in G:
    print(*g)