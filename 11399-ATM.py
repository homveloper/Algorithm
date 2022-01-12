from sys import stdin

input = stdin.readline

N = int(input())
L = sorted(list(map(int, input().split())))
result = 0
cost = 0
for i in L:
    cost += i
    result += cost

print(result)