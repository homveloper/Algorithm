import sys; input = sys.stdin.readline

# 판때기 크기
height, width = map(int,input().split())

# 이동할 좌표
dx = [1,0,-1,0]
dy = [0,1,0,-1]

# 판때기
board = [list(map(lambda x : ord(x) - 65 , input())) for _ in range(height)]

# 알파벳의 visited 여부
alphabets = [0 for _ in range(26)]

# 최대 거리
max_dist = 0

def recursive_dfs(y,x, dist):
    global max_dist

    if max_dist <= dist:
        max_dist = dist

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if  0 <= nx < width and 0 <= ny < height and alphabets[board[ny][nx]] == 0:
            alphabets[board[ny][nx]] = 1
            dist += 1
            recursive_dfs(ny,nx, dist)
            alphabets[board[ny][nx]] = 0
            dist -= 1

def queue_dfs(y,x):
    pass

alphabets[board[0][0]] = 1
recursive_dfs(0,0,1)
print(max_dist)