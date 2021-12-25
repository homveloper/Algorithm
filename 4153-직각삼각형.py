import sys

for i in sys.stdin.readlines()[:-1]:
    a,b,c = sorted(map(int,i.split()))
    print("right" if a**2 + b**2 == c**2 else "wrong")