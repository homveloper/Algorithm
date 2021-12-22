N = int(input())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

result = 0

for i,j in zip(sorted(A), sorted(B,reverse=True)):
    result += i*j

print(result)