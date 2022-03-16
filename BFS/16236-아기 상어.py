from collections import deque
from dis import dis
from tabnanny import check

N = int(input())
B = [list(map(int,input().split())) for _ in range(N)]
size = 2
current_eated = 0

D = [[-1,0],[0,-1],[0,1],[1,0]]
pos = [[y, row.index(9)] for y, row in enumerate(B) if 9 in row]

def distance(a : list, b :list):
    return abs(b[0]-a[0]) + abs(b[1]-a[1])

def serach_target(vector2 : list):
    q = deque([vector2])

    visited = [[-1] * N for _ in range(N)]
    visited[vector2[0]][vector2[1]] = 0

    min_x, min_y, min_dist = N, N, N**2+1

    while q:
        y,x = q.popleft() 
        for dy, dx in D:
            ny, nx = y+dy, x+dx

            if ny < 0 or ny >= N or nx < 0 or nx >=N: continue
            if visited[ny][nx] != -1 or B[ny][nx] > size: continue

            visited[ny][nx] = visited[y][x] + 1
            if 0 < B[ny][nx] < size:

                dist = visited[ny][nx]

                if min_dist > dist:
                    min_x = nx
                    min_y = ny
                    min_dist = dist
                elif min_dist == dist:
                    if min_y == ny and min_x > nx:
                        min_x = nx
                        min_y = ny
                    elif min_y > ny:
                        min_x = nx
                        min_y = ny

            q.append([ny,nx])

    return min_y, min_x, min_dist

def bfs(vector2 : list):
    global size, current_eated

    q = deque([vector2])
    B[vector2[0]][vector2[1]] = 0
    result = 0

    while q:
        ny, nx,dist = serach_target(q.popleft())
        if ny != N and nx != N:
            current_eated += 1

            if current_eated == size:
                size += 1
                current_eated = 0

            B[ny][nx] = 0
            result += dist
            q.append([ny,nx])
        else:
            break

    print(result)

bfs(pos[0])