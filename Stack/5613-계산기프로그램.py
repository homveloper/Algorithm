operator = ''
result = int(input())

while(True):
    i = input()

    if i == '=':
        break

    if i in ['+','-','/','*']:
        operator = i
        continue
    
    if operator == '+':
        result += int(i)
    elif operator == '-':
        result -= int(i)
    elif operator == '/':
        result = int(result / int(i))
    elif operator == '*':
        result *= int(i)
    
print(result)