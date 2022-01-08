from sys import stdin

input = stdin.readline

N = int(input())
result = 10000
result_idx = -1

for i in range(N):

    J, M = map(int, input().split())
    R = (J-1) % (M+1)
    count = (J - R) // (M+1) + 1
    count *= 2

    if result > count:
        result = count
        result_idx = i

print(result_idx+1, result)