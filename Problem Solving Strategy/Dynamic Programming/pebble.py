import random as rand
from pprint import pprint
import sys

sys.setrecursionlimit(100000)

w = [[rand.randint(0,10) for j in range(20)] for i in range(3)]

pattern = [
    [0,1,1,0],
    [1,0,1,1],
    [1,1,0,0],
    [0,1,0,0]
]


def pebble(i,p):
    if i == 0:
        if(p<3):
            return w[p][1]
        else:
            return w[0][1]+w[2][1]

    else:
        max = sys.maxsize

        for q in range(4):

            if pattern[p][q]:
                temp = pebble(i-1,q)
                max = temp if temp < max else max

        print(i,"pattern : ",p)
        if(p<3):
            return w[p][i] + max
        else:
            return w[0][i]+w[2][i] + max


pprint(w)

def pebbleSum(n):
    return max(pebble(n,0),pebble(n,1),pebble(n,2),pebble(n,3))

print(pebbleSum(1))