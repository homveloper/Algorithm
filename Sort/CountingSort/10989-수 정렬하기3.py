import sys
input = sys.stdin.readline

N = int(input())
L = [0] * 10001

for _ in range(N):
    L[int(input())] += 1

for i,c in enumerate(L):
    for _ in range(c):
        print(i)