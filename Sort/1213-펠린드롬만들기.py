string = input()
count = [0 for i in range(26)]
perlin = ''
middle = ''

# count 세기
for i in string:
    count[ord(i)-ord('A')] += 1

if len(string) % 2 == 1:
    for i,c in enumerate(count):
        if c % 2 == 1:
            middle = chr(65+i)
            count[i] -= 1
            break;

half_count = len(string) // 2

for i,c in enumerate(count):
    if half_count == 0:
        break

    if c != 0:
        num = c//2
        count[i] -= num

        for _ in range(num):
            perlin += chr(65+i)
    
        half_count -= 1

for i in perlin[::-1]:
    count[ord(i)-ord('A')] -= 1

is_perline = sum(count) == 0

if is_perline:
    if len(string) % 2 == 1:
        print(perlin, middle, perlin[::-1],sep='')
    else:
        print(perlin,perlin[::-1],sep='')
else:
    print("I'm Sorry Hansoo")