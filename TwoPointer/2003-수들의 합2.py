from sys import stdin
input = stdin.readline

N, M = map(int,input().split())
L = list(map(int, input().split()))

i,j,count = 0,0,0

while j<=N:

    result = sum(L[i:j])

    if result == M:
        count += 1
        i+=1
        j+=1
    elif result < M:
        j+=1
    else:
        i+=1

print(count)