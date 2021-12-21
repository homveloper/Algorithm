N = int(input())
expression = input()
stack = []
operand = {}

for i in expression:
    if 'A' <= i <= 'Z' and not i in operand:
        operand[i] = int(input())

for i in expression:
    if 'A' <= i <= 'Z':
        stack.append(operand[i])

    elif i == '*':
        b = stack.pop()
        a = stack.pop()
        stack.append(a*b)

    elif i == '+':
        b = stack.pop()
        a = stack.pop()
        stack.append(a + b)

    elif i == '/':
        b = stack.pop()
        a = stack.pop()
        stack.append(a/b)

    elif i == '-':
        b = stack.pop()
        a = stack.pop()
        stack.append(a-b)
    
print(f'{stack[-1]:.2f}')