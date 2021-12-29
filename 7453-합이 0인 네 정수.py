'''
AB배열를 기준 CD 사전의 원소 찾기
- N^2 + N^2 * alpha
- alpha : O(1) or O(N)

A,B,C,D 배열의 나올수 있는 모든 경우의 수
- N^4
'''
from sys import stdin
from collections import defaultdict
input = stdin.readline

N = int(input())
L = [list(map(int, input().split())) for i in range(N)]

A = [i[0] for i in L]
B = [i[1] for i in L]
C = [i[2] for i in L]
D = [i[3] for i in L]

count = 0
CD = defaultdict(int)

for c in C:
    for d in D:
        CD[c+d] += 1

for a in A:
    for b in B:
        if -(a+b) in CD:
            count+= CD[-(a+b)]
print(count)