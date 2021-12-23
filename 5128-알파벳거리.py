def length(a,b):
    if a <= b:
        return ord(b) - ord(a)
    else:
        return ord(b) + 26 - ord(a)

T = int(input())

for i in range(T):
    A,B = input().split()
    print("Distances:", *[length(a,b) for a,b in zip(A,B)])