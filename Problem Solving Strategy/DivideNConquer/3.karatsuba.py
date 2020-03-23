import time
import random

"""
    카라츠바 곱셈

    일반적인 긴 자연수의 곱셈은 O(n^2)입니다. 이는 multiply() 함수에서
    나타나고 있습니다. 

    a와 b를 256자리의 수라고 한다면 첫 128자리 수는 a0, 그다음은 a1라 합니다.
    b도 마찬가지로 동일하게 합니다. 

    a = a0 * 10^128 + a1
    b = b0 * 10^128 + b1

    a * b = (a0 * 10^128 + a1)(b0 * 10^128 + b1)
          = a0b0*10^256 + a0b1*10^128 + a1b0*10^128 + a1b1
          = a0b0*10^256 + (a0b1 + a1b0)10^128 + a1b1

    이식은 4번의 곱셈을 수행하고 있습니다. 여기서 카라츠바는 3번의 곱셈으로 식을 바꿨습니다.

    a0b0를 z2, a0b1 + a1b0를 z1, a1b1을 z0라고 하면

    (a0 + a1)(b0 + b1) = a0b0 + a0b1 + a1b0+ a1b1
                       = z2 + z1 + z0

    이므로 z1 = (a0 + a1)(b0 + b1)-z0-z2 가 됩니다.

"""


# num의 자릿수 올림을 처리한다.
def nomalize(num):
    num.append(0)
    
    for i in range(len(num)-1):
        if num[i] < 0 :
            borrow = (abs(num[i]) + 9)//10
            num[i+1] = num[i+1] - borrow
            num[i] = num[i] + borrow*10
        else:
            num[i+1] = num[i+1] + num[i] // 10
            num[i] = num[i] % 10

    while len(num) > 1 and num[-1] == 0:
        num.pop()

# 두 자연수의 곱을 반환
def multiply(a,b):
    c = [0 for i in range(len(a) + len(b))]

    for i in range(len(a)):
        for j in range(len(b)):
            c[i+j] = c[i+j] + a[i] * b[j]
    
    nomalize(c)

    return c

# a += b*(10^k)를 구현
def addTo(a,b,k):   

    s = max(len(a), len(b) + k)

    a = a + [0 for i in range(s - len(a))]
    b = b + [0 for i in range(s - len(b))]

    for i in range(0,s-k):
        a[i+k] = a[i+k] + b[i]

    nomalize(a)

def subFrom(a,b):
    s = max(len(a),len(b))

    a = a + [0 for i in range(s - len(a))]
    b = b + [0 for i in range(s - len(b))]

    for i in range(s):
        a[i] = a[i] - b[i]

    nomalize(a)

# 카라츠바의 빠른 정수 곱셈
def karatsuba(a,b):
    len_a = len(a)
    len_b = len(b)

    if len_a < len_b:
        return karatsuba(b,a)
    
    if len_a == 0 or len_b == 0:
        return []

    if len_a <= 50:
        return multiply(a,b)

    half = len_a // 2

    a0 = a[:half]
    a1 = a[half:]

    b0 = b[:min([len_b,half])]
    b1 = b[min([len_b,half]):]

    z2 = karatsuba(a1,b1)
    z0 = karatsuba(a0,b0)

    addTo(a0,a1,0)
    addTo(b0,b1,0)

    z1 = karatsuba(a0,b0)
    subFrom(z1,z0)
    subFrom(z1,z2)

    result = []

    addTo(result,z0,0)
    addTo(result,z1,half)
    addTo(result,z2,half+half)
    
    return result

def getLongNum(length):
    return [random.randint(0,9) for i in range(length)]

if __name__ == "__main__":
    a = getLongNum(1000)
    b = getLongNum(1000)

    # print("a : ",*a[::-1])
    # print("b : ",*b[::-1])

    # 기본적인 곱셈 방법
    start = time.time()
    result = multiply(a,b)
    print("time : ",time.time()-start)
    # print(*result[::-1])

    # 카라츠바 곱셈
    start = time.time()
    result = karatsuba(a,b)
    print("time : ",time.time()-start)
    # print(*result[::-1])
