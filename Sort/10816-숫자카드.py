N = int(input())
cards = {}

for i in map(int,input().split()):
    if i not in cards:
        cards[i] = 0

M = int(input())
keys = list(map(int,input().split()))

print(*map(lambda x : 1 if x in cards else 0, keys))