from sys import stdin
input = stdin.readline

def fpow(n,r):
    if r == 1:
        return n
    
    x = fpow(n, r//2)

    if r % 2 == 0:
        return x * x % 1000000007
    else:
        return ((x * x)% 1000000007) * n % 1000000007

M = int(input())
L = [list(map(int, input().split())) for _ in range(M)]
result = 0

for [n,s] in L:
    result += s * fpow(n,1000000005) % 1000000007
    result %= 1000000007

print(result)
