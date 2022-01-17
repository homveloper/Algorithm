from sys import stdin
input = stdin.readline

N = int(input())
B = [list(map(int, input().split())) for _ in range(N)]

# -1, 0, 1
R = {-1:0,0:0,1:0}


def condition(y : int, x: int, offset : int) -> bool:
    num = B[y][x]
    
    for i in range(offset):
        for j in range(offset):
            if num != B[y+i][x+j]:
                return False
    
    return True

def solution(y : int, x : int, offset : int):
    if condition(y,x,offset):
        R[B[y][x]] += 1
    else:
        for i in range(3):
            for j in range(3):
                solution(y+i * offset//3,x + j*offset//3, offset//3)

solution(0,0,N)
print(*R.values(),sep='\n')