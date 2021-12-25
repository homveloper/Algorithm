import sys
import math
N = int(input())
arr = list(map(int, sys.stdin.readlines()))
arr.sort()

# -4000 ~ 4000
frequency = [0] * 8001

print(round(sum(arr)/N))
# 0 1 2  (3-1)//2
print(arr[(N-1)//2])

# 0 : -4000 ~ 8000 : 4000
for i in arr:
    frequency[i + 4000] += 1

max_count = max(frequency)
max_arr = [i-4000 for i,f in enumerate(frequency) if max_count == f]

print(max_arr[1] if len(max_arr) >= 2 else max_arr[0])
print(arr[-1] - arr[0])