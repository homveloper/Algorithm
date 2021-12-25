num = input()

while num != '0':
    print("yes" if num == num[::-1] else "no")
    num = input()