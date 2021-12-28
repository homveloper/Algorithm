def fibonacci(n):
    global zero, one

    if n == 0:
        zero += 1
        return 0
    elif n == 1:
        one += 1
        return 1
    
    return fibonacci(n -1) + fibonacci(n - 2)

if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        zero = 0
        one = 0

        fibonacci(int(input()))

        print(zero, one)