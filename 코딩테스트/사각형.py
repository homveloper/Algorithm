from math import factorial


D = [[19,17]]
R = 37
C = 51

'''
2<= N <= 250
y+x C x
'''

sum = [[0 for _ in range(101)] for _ in range(101)]

def Comb(n : int,r : int)->int:
    global sum
    
    if sum[n][r]:
        return sum[n][r]
    
    if n == r or r == 0:
        return 1
    else:
        sum[n][r] = Comb(n-1,r-1) + Comb(n-1,r)
        return sum[n][r]

# log(N)

def reset():
    global sum

    sum = [[0 for _ in range(101)] for _ in range(101)]

def Comb2(n : int, r : int)->int:
    return factorial(n+r)%10000019 / ((factorial(n-r) * factorial(r)))

if __name__ == "__main__":
    answer = 0
    for [y,x] in D:
        # 왼쪽 위에서 아래로 갈 때
        
        reset()
        a = Comb(y+x-1, y)
        reset()
        b = Comb(R+C-(x+y-1), R-y-1)

        answer += (a * b) % 10000019

        # 오른쪽 아래에서 위로 갈 때
        reset()
        a = Comb(y+x-1, x)
        reset()
        b = Comb(R+C-(x+y-1), C-x-1)
        answer += (a*b) % 10000019

    print(answer)