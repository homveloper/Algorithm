from collections import defaultdict

N = int(input())
DP = [0] * (N+1)
L = [0] * (N+1)

for i in range(2, N+1):
    DP[i] = DP[i-1] + 1
    L[i] = i-1
    L[i].append(i-1)

    if i%2 == 0:
        if DP[i] > DP[i//2] + 1:
            DP[i] = DP[i//2] + 1
            L[i] = i//2
            L[i].append(i//2)

    if i%3 == 0:
        if DP[i] > DP[i//3] + 1:
            DP[i]  = DP[i//3] + 1
            L[i] = i//3
            L[i].append(i//3)

cnt = DP[N]
tmp = N
print(cnt)
print(N, end=' ')
while cnt >= 1:
    print(L[tmp], end=' ')
    tmp = L[tmp]
    cnt -= 1 