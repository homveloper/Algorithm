"""
종결규칙
1. 이동 경로의 수가 도시의 수와 동일할 경우 종료

여행하는 외판원 문제
"""
import random
import pprint

n = int(input("도시 수 : "))
distance = [[random.randint(1,10) for i in range(n)] for j in range(n)]
path = [0]
visited = [False for i in range(n)]
visited[0] = True

def shortestPath(path,visited,currentLength):

    if len(path) == n:
        return currentLength + distance[path[0]][path[-1]]
    
    result = 10000000000

    for next in range(n):

        if visited[next]:
            continue

        here = len(path) -1
        path.append(next)
        visited[next] = True
        candidate = shortestPath(path,visited,currentLength + distance[here][here])
        result = min(result,candidate)
        visited[next] = False
        path.pop()

    return result

pprint.pprint(distance)
print(shortestPath(path,visited,0))