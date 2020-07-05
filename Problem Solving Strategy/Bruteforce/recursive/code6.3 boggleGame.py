import random
from pprint import pprint

def createBoard(n):
    return [[chr(ord('A') + random.randint(0,25)) for i in range(n)] for j in range(n)]

def inRange(y,x):
    return 0<=y<=5 and 0<=x<=5

dx = [-1,-1,-1,1,1,1,0,0]
dy = [-1,0,1,-1,0,1,-1,1]

def hasWord(y,x,word):

    # x와 y가 보드 범위를 넘어서는지 학인
    if not inRange(y,x): 
        return False

    # 첫 글자가 일치하는지 확인
    if board[y][x] != word[0]:
        return False

    # 단어 길이가 1인지 확인
    if len(word) <= 1:
        return True

    for direction in range(8):
        
        nextY = y + dy[direction]
        nextX = x + dx[direction]

        if hasWord(nextY,nextX, word[1:]):
            return True


board = createBoard(5)
pprint(board)

print(hasWord(0,0,"TE"))
