import sys

input = sys.stdin.readline
inputs = sys.stdin.readlines

T = int(input())
L = list(map(int, inputs()))

DP = [[0,0] for i in range(41)]

def fibonacci(n):

    if n == 0:
        return [1,0]
    elif n == 1:
        return [0,1]

    if DP[n][0] or DP[n][1]:
        return DP[n]
    else:
        A = fibonacci(n -1)
        B = fibonacci(n - 2) 
        DP[n][0] = A[0] + B[0]
        DP[n][1] = A[1] + B[1]
        return DP[n]

for i in L:
   print(*fibonacci(i))