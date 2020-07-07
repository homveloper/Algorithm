
coverType = [
    [[0, 0], [1, 0], [0, 1]],
    [[0, 0], [0, 1], [1, 1]],
    [[0, 0], [1, 0], [1, 1]],
    [[0, 0], [1, 0], [1, -1]]
]

# 블록이 제대로 덮이지 않은 경우 (게임판 밖을 나가거나, 겹치거나, 검은 칸을 덮을 떄) false를 반환


def set(board, y, x, type, delta):
    ok = True

    for i in range(3):
        ny = y + coverType[type][i][0] 
        nx = x + coverType[type][i][1]

        if ny < 0 or ny >= len(board) or nx < 0 or nx >= len(board[0]):
            return False
        else:
            board[ny][nx] += delta

        if board[ny][nx] > 1:
            ok = False


    return ok


def cover(board):

    y = -1
    x = -1

    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 0:
                y = i
                x = j
                break

        if y != -1:
            break

    # 기저 사례 : 모든 칸을 채웠으면 1을 반환
    if y == -1:
        return 1

    result = 0
    for type in range(4):

        # 만약 board[y][x]를 type 형태로 덮을 수 있으면 재귀 호출한다.
        if(set(board, y, x, type, 1)):
            result += cover(board)

        set(board, y, x, type, -1)

    return result


board = [[1, 0, 0, 0, 0, 0, 1],
         [1, 0, 0, 0, 0, 0, 1],
         [1, 1, 0, 0, 0, 1, 1]]

board = [[1, 0, 0, 0, 0, 0, 1],
         [1, 0, 0, 0, 0, 0, 1],
         [1, 1, 0, 0, 1, 1, 1]]

board = [[1] * 10,
         [1] + [0] * 8+[1],
         [1] + [0] * 8+[1],
         [1] + [0] * 8+[1],
         [1] + [0] * 8+[1],
         [1] + [0] * 8+[1],
         [1] + [0] * 8+[1],
         [1] * 10]

print(cover(board))