'''
배낭 문제

다이나믹 프로그래밍으로 매우 유명한 문제.

어떤 배낭이 있고, 그 배낭안에 넣을 수 있는 최대 무게가 K이다. 배낭에 넣을 수 있는 N개의 물건과 그 가치인 V와 무게인 W가 있다. 배낭을 최대한 채우면서, 가치가 높은 물건들을 담을 수 있는 조합을 찾는 문제이다.


Brute Force 접근

N개의 물건이 있을 때 가능한 모든 조합은 2^N의 경우의 수 이므로 O(2^N)이기에 시간 초과가 날수 있다.

Dynamic Programming 접근

현재의 문제를 작은 문제로 정의하는 것을 해야 한다. 현재 가방의 무게에서 특정 물건을 넣거나 넣지 않는 식으로 문제를 나눠가야한다.

B[k][W] = B[k-1][W], if w_k > W

물건을 넣을 수 있는 무게가 조금이라도 남아있다면 선택지는 두가지이다.
- 새로운 물건을 넣지 않는다.
- 새로운 물건을 넣기 위해 현재 물건을 넣을 공간을 만들어 물건을 넣는다.

이 중 가지가 더 커지는 쪽으로 선택하면 된다.

B[k][W] = max(B[k-1][W], B[k][W-w_k] + val(w_k))

'''
from sys import stdin
input = stdin.readline

N,K = map(int, input().split())
L = [list(map(int, input().split())) for _ in range(N)]

DP = [[0]*(K+1) for _ in range(N+1)]

for n in range(1,N+1):
    for k in range(1,K+1):
        if L[n-1][0] <= k:
            DP[n][k] = max(L[n-1][1] + DP[n-1][k-L[n-1][0]], DP[n-1][k])
        else:
            DP[n][k] = DP[n-1][k]
    
print(DP[N][K])