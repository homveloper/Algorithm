from sys import stdin

input = stdin.readline
inputs = stdin.readlines

N, D, K, C = map(int,input().split())
L = [int(i) for i in inputs()]

i = 0
j = K
result = 0

while i<N:

    shusi = set()
    if i < j:
        shusi = set(L[i:j])
    else:
        shusi = set(L[i:]) | set(L[:j])

    count = len(shusi)

    if C not in shusi:
        count += 1

    result = max(count,result)

    i+=1
    j+=1
    if j > N:
        j = 1

print(result)