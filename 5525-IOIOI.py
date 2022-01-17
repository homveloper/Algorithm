from sys import stdin
input = stdin.readline

N = int(input())
M = int(input())
S = input().strip()

def IOI(n : int):
    return 'I' + 'OI'*n

def occurrences(string, sub):
    count = start = 0
    while True:
        start = string.find(sub, start) + 2
        if start > 1:
            count+=1
        else:
            return count

print(occurrences(S,IOI(N)))