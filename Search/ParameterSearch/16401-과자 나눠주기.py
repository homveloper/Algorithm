import sys; input = sys.stdin.readline

M, N = map(int, input().split())
L = list(map(int, input().split()))

answer = 0
low = 1
high = max(L)

def is_possible(mid):
    count = 0 

    for i in L:
        count += i // mid

        if count >= M:
            return True
    
    return False

while low <= high:
    mid = (low + high) // 2
    if is_possible(mid):
        answer = max(answer,mid)
        low = mid + 1
    else:
        high = mid - 1

print(answer)