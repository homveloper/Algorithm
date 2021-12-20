import sys
msg = ''.join(sys.stdin.readlines()).replace('\n','').replace(' ','')
count = list(map(msg.count, [chr(97 + i) for i in range(26)]))
max_value = max(count)
print(*[chr(97+i) for i,c in enumerate(count) if c == max_value],sep='')