'''
현재 n 번째 위치에서 1, 3, 4개 가져갈때, 즉
dp[n-1], dp[n-3], dp[n-4]일 때 창영이가 이긴다면
그다음 dp[n]은 상근이가 이길 수 있다.

'''

def solution(N):
    dp = [0] * 1001
    dp[1] = 1
    dp[2] = 0
    dp[3] = 1
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
        return "SK"
        # print("SK")
    else:
        print("CY")
        return "CY"

for i in range(1, 100):
    solution(i)
