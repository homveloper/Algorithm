from sys import stdin
import heapq

input = stdin.readline

T = int(input())

for _ in range(T):

    K = int(input())
    H = []
    min_value = []

    for _ in range(K):
        cmd = input().split()

        if cmd[0] == 'I':
            heapq.heappush(H, -int(cmd[1]))
        else:
            if not H:
                continue

            if cmd[1] == '1':
                print(heapq.heappop(H))
            else:
                min_value.append(heapq.nsmallest(1,H)[0])
                print(min_value)

    if len(H) > len(min_value):
        print(-heapq.nlargest(1,H), min_value)
    else:
        print("EMPTY")