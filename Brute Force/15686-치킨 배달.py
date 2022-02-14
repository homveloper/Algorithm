'''
치킨 배달

치킨 거리 : 집과 가장 가까운 치킨집

'''
from itertools import combinations
from sys import stdin
input = stdin.readline

CHICKEN = 2
HOUSE = 1
INF = 100000000

N, M = map(int, input().split())
B = [list(map(int, input().split())) for _ in range(N)]
chickens = []
houses = []
result = INF

def find_shortest_distance(house, targets):
    min_distance = INF

    for target in targets:
        distance = abs(target[0] - house[0]) + abs(target[1] - house[1])
        min_distance = min(distance, min_distance)

    return min_distance

for y in range(N):
    for x in range(N):
        if B[y][x] == CHICKEN:
            chickens.append((y,x))
        elif B[y][x] == HOUSE:
            houses.append((y,x))

for m in range(1,M+1):
    for cases in combinations(chickens,m):
        sum_of_distance = 0
        for h in houses:
            sum_of_distance += find_shortest_distance(h,cases)
        
        result = min(result, sum_of_distance)

print(result)