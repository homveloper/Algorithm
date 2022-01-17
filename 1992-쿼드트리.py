from sys import stdin
input = stdin.readline

N = int(input())
IMAGE = [list(map(int,input().strip())) for _ in range(N)]
result = []

def is_same(y : int,x : int,offset : int) -> bool:
    pixel = IMAGE[y][x]

    for i in range(offset):
        for j in range(offset):
            if pixel != IMAGE[y+i][x+j]:
                return False
    
    return True

def solution(y : int, x : int, offset : int) -> None:
    if is_same(y,x,offset):
        result.append(IMAGE[y][x])
    else:
        result.append('(')
        for i in range(2):
            for j in range(2):
                solution( y+i*offset//2, x+j*offset//2, offset//2)
        result.append(')')

solution(0,0,N)
print(*result,sep='')