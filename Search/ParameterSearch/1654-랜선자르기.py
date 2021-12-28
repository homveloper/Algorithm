import sys

input = sys.stdin.readline
inputs = sys.stdin.readlines    

K,N = map(int,input().split())
L = list(map(int,[i for i in inputs()]))

low = 1
high = sum(L)
result = low

def is_possible(mid):

    cnt = 0

    for i in L:
        cnt += i // mid

    return cnt >= N

while low<=high:

    mid = (low+high)//2

    if is_possible(mid):
        result = max(result,mid)
        low = mid+1
    else:
        high = mid-1

print(result)   