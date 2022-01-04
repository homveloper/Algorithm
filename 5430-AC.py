from sys import stdin
from collections import deque

input = stdin.readline

T = int(input())

for _ in range(T):
    P = input()
    N = int(input())
    L = deque(input().strip()[1:-1].split(','))

    if N == 0:
        L = deque()

    error = False
    reverse = False

    for p in P:
        if p == 'R':
            reverse = not reverse
        
        elif p == 'D':
            try:
                if reverse:
                    L.pop()
                else:
                    L.popleft()
            except:
                error = True
                break
    
    if error:
        print('error')
    else:
        if reverse:
            L.reverse()

        print(f'[{",".join(L)}]')