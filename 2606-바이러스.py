from collections import deque

C = int(input())
E = int(input())

graph = {}
visited = [0 for _ in range(C+1)]

for i in range(C): 
    graph[i+1] = []

for i in range(E):
    s,e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)

count = 0

def recursive_dfs(vertex):
    global count

    for i in graph[vertex]:
        if not visited[i]:
            visited[i] = 1
            count += 1
            recursive_dfs(i)

def stack_dfs(vertex):
    global count

    stack = deque()
    stack.append(vertex)

    while stack:
        for i in graph[stack.pop()]:
            if not visited[i]:
                visited[i] = 1
                count += 1
                stack.append(i)

visited[1] = 1
stack_dfs(1)
print(count)