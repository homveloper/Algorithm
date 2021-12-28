import sys
input = sys.stdin.readline
inputs = sys.stdin.readlines


N,M = map(int, input().split())
L = list(map(int, inputs()))

low = 1
high = sum(L)
result = high

def is_possible(mid):
    money = 0
    cnt = 0

    if mid < max(L):
        return False

    for i in L:
        if money >= i:
            money -= i
        else:
            money = mid - i
            cnt += 1

    return cnt <= M

while low<=high:

    mid = (low+high)//2

    if is_possible(mid):
        result = min(result, mid)
        high = mid-1
    else:
        low = mid +1

print(result)