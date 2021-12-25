N = int(input())
operands = list(map(int, input().split()))
num_of_operator = list(map(int, input().split()))


# 10P10 10! => 3628800

'''
operator
0 : +
1 : -
2 : *
3 : //
'''

def permutation(arr,n):
    result = []

    if n == 0:
        return [[]]

    for i, e in enumerate(arr):
        for p in permutation(arr[:i] + arr[i+1:], n-1):
            result += [[e] + p]
    
    return result

def caculate(operands,operators):
    result = operands[0]

    for i,j in zip(operands[1:],operators):
        if j == 0:
            result += i
        elif j == 1:
            result -= i
        elif j == 2:
            result *= i
        elif j == 3:
            if result < 0:
                result = -(-result // i)
            else:
                result //= i

    return result

flatten_operator = []

for i,n in enumerate(num_of_operator):
    for j in range(n):
        flatten_operator.append(i)

min_value = 1e9
max_value = -1e9

for operators in permutation(flatten_operator,N-1):
    result = caculate(operands,operators)

    max_value = min(result,max_value)
    min_value = min(result,min_value)

print(max_value)
print(min_value)