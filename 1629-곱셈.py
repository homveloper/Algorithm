'''
pow(A,B) = A*A*A*A*A*A*A  B개 만큼 곱셈이므로 O(n)임

즉 B가 21억이면 21초가 걸릴수 있으므로 분할정복을 통해

pow(A,16) = 
    2pow(A,8)
    4pow(A,4)
    8pow(A,2)
    16pow(A,1)

로 4번 만에 구할 수 있음, 즉 log_2(n)임

'''

A,B,C = map(int,input().split())

def solution(a,b,c):

    if b == 1:
        return a

    result = solution(a, b//2, c)

    if b % 2:
        return result % c * result %c * a
    else:
        return result %c * result %c

print(solution(A,B,C) % C)