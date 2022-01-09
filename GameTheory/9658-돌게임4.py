'''
dp[i] : i번째 위치에서
i-1, i-3, i-4 창영이가 진다면,
i번째에서는 상근이가 지게 된다.

1 = 상근이가 이김
0 = 창영이가 이김
'''

N = int(input())
dp = [0] * 1001
dp[1] = 0
dp[2] = 1
dp[3] = 0
dp[4] = 1
dp[5] = 1

for i in range(6,N+1):
    if dp[i-1] == 0:
        dp[i] = 1

    if dp[i-3] == 0:
        dp[i] = 1
    
    if dp[i-4] == 0:
        dp[i] = 1

if dp[N] == 1:
    print("SK")
else:
    print("CY")