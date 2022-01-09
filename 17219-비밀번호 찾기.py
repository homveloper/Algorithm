from sys import stdin, stdout
from collections import defaultdict

input = stdin.readline

N, M = map(int, input().split())
L = defaultdict(str)

for _ in range(N):
    address, password = input().strip().split()
    L[address] = password

for _ in range(M):
    print(L[input().strip()])