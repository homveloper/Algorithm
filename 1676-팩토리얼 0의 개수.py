from math import factorial

N = int(input())

count = 0
for i in str(factorial(N))[::-1]:
    if i == '0':
        count += 1
    else:
        break
print(count)