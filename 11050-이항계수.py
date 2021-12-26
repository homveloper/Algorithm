# (n,k) or nCk = (n-1,k)+(n-1,k-1)

def combination(n,k):
    if n == k or k == 0:
        return 1

    return combination(n-1,k) + combination(n-1,k-1)

print(combination(*map(int,input().split())))
