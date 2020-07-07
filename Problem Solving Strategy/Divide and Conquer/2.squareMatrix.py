"""
    행렬의 거듭제곱

    A^m = A^m/2 * A^m/2

    m이 짝수
    A^m = A^m/2 * A^m/2

    m이 홀수
    A^m = A^(m-1) * A

    종결조건
    if m == 1 : return 항등행렬
"""
import random
import time
import pprint


# n*n 크기의 항등 행렬
def identity(n):
    E = []
    for i in range(n):
        temp = []
        for j in range(n):
            if j == i:
                temp.append(1)
            else:
                temp.append(0)
        E.append(temp)
    return E

# 행렬 곱
def matrixMul(A, B):
    matrix = []
    for idx1 in range(len(A)):
        row = []
        for idx2 in range(len(B[0])):
            tmp = 0
            for idx3 in range(len(A[0])):
                tmp += A[idx1][idx3] * B[idx3][idx2]
            row.append(tmp)
        matrix.append(row)
    return matrix

# A : 행렬
# m : 제곱수
def matrixPow(A, m):
    if m == 0:
        return identity(len(A))
    if m % 2 > 0:
        return matrixMul(matrixPow(A, m-1),A)
    half = matrixPow(A, m/2)

    return matrixMul(half,half)

def randomSquare(n):
    matrix = []

    for i in range(n):
        row = []
        for j in range(n):
            row.append(random.randint(0, n))
        matrix.append(row)

    return matrix

# def iterablePow(A,m):
#     for i in range(m-1):
#         A = matrixMul(A,A)

#     return A

if __name__ == "__main__":
    n,m = 2,3

    A = randomSquare(n)
    pprint.pprint(A)

    start = time.time()
    print("분할정복의 행렬곱")
    pprint.pprint(matrixPow(A, m))
    print("소요시간 : ", time.time()-start)

    # start = time.time()
    # print("반복문의 행렬곱")
    # pprint.pprint(iterablePow(A, 5))
    # print("소요시간 : ", time.time()-start)
