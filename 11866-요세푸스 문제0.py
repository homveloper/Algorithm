N,K = map(int, input().split())
arr = [i for i in range(1,N+1)]
i = K-1

result = []
while True:
    result.append(arr[i])
    del arr[i]

    if len(arr) == 0:
        break

    i += K-1
    i = i % len(arr)

print("<",end='')
for i in result[:-1]:
    print(f'{i}, ',end='')
print(f'{result[-1]}>')