N = int(input())
cards = {}

for i in map(int,input().split()):
    if i not in cards:
        cards[i] = 1
    else:
        cards[i] += 1

M = int(input())
keys = list(map(int,input().split()))

print(*map(lambda x : cards.get(x, 0), keys))