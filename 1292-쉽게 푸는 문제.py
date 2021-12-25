
# 길이가 1000인 배열을 만들어 부분합을 구하는 방법
def solution1():
    arr = [0]*1001

    num = 1
    repeat = 0
    for i in range(1,1001):
        repeat += 1
        arr[i] = num

        if num == repeat:
            repeat = 0
            num += 1

    a,b = map(int,input().split())
    print(sum(arr[a:b+1]))

# 군수열을 이용한 방법
def solution2():
    '''
    군수열을 이용하여 n에 따른 a_n의 값을 구하는 문제
    계차수열에 따라 각 숫자가 시작하는 위치는

    a_n = 1 + n(n-1)/2 이고.
    a_3 = 4이므로, 3은 4번째부터 시작한다는 의미이다. 역으로
    4번째 위치에 있는 숫자는 3이므로

    a_2 = 2

    x = 1 + n(n-1)/2

    x값에 따른 n의 근을 구하면 된다. 근의 공식을 이용하여

    n^2 -n -2(x-1) = 0

    n = 1 + sqrt(1 + 8(x-1))// 2

    결국 공식은. f(x) = 1 + sqrt(8x - 7) // 2

    1 2 2 3 3 3 4 4 4 4 5 5 5 5 5 6 6 6 6 6 6 7 7 7 7 7 7 7

    f(1) = 1
    f(2) = 2
    f(3) = 3
    f(4) = 3
    f(5) = 3
    f(6) = 4
    f(7) = 4
    '''

    from math import sqrt
    a,b = map(int,input().split())
    sum = 0
    for i in range(a, b+1):
        v = 1 + int(sqrt(8 * i  - 7)) // 2
        print(v)
        sum += v

    print(sum)

solution1()