from itertools import combinations

L,C = map(int, input().split())
E = sorted(input().split())

vowel = set(['a','e','i','o','u'])
consonant = set([chr(i +97) for i in range(26)]) - vowel

def condition(c:list):
    vowel_count = 0
    consonant_count = 0

    for i in c:
        if i in vowel:
            vowel_count += 1
        
        elif i in consonant:
            consonant_count += 1

    return vowel_count >= 1 and consonant_count >= 2

for c in combinations(E,L):
    if condition(c):
        print(*c, sep='')