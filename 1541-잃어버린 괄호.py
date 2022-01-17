L = input().split('-')

flag = False
if L[0] == '':
    L = L[1:]
    flag = True

result = 0
for idx,l in enumerate(L):
    if flag and idx == 0:
        result += sum(map(int, l.split('+')))
    elif not flag and idx == 0:
        result -= sum(map(int, l.split('+')))
    else:
        result += sum(map(int, l.split('+')))

print(-result)