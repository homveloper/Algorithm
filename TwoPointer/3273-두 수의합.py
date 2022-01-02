from sys import stdin

input = stdin.readline

N = int(input())
L = sorted(list(map(int, input().split())))
X = int(input())
count = 0

i = 0
j = N-1

while i<j:
    if L[i] + L[j] == X:
        count += 1
        i+=1
        j-=1
    elif L[i] + L[j] < X:
        i+=1
    else:
        j-=1

print(count)