from bisect import bisect_left,bisect_right

# arr 정렬 후 이진 탐색 : O(NlogN) + O(2NlogN) => (N+2N)logN
# N개에 대해서 해쉬 탐색 : O(N^2) => N^2
# N = 1e5  3e5 * log(1e5) <<< 1e10  

N = int(input())
arr = list(map(int, input().split()))
M = int(input())
query = list(map(int, input().split()))

arr.sort()

for q in query:
    print(int(bisect_right(arr,q) != bisect_left(arr, q)))