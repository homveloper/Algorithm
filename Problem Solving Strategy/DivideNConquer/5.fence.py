"""
    울타리 잘라내기

    너비가 같은 N개의 나무 판자들로 세운 울타리가 있습니다.
    시간이 지남에 따라 울타리들이 부서져 높이가 달라진 관계로
    새롭게 교체할려고 합니다. 이때 기존의 나무판자를 재활용하여
    쓸려고합니다. 가장 많이 재활용할 수 있는 직사각형 형태의 나무
    판자의 넓이를 구하시오.

    완전탐색(BruteForce)

    만약 각 판자의 높이가 주어진 배열 h[]에서 l번 부터 r번 까지의 판자를
    잘라 직사각형으로 만든다고 한다.

    (r - l + 1) * min(h[r:l])

    2중 for문으로 l과 r을 순회하며 최대 값을 찾아내는 것입니다. 
    하지만 최대 입력 개수가 2만이므로 O(n^2)시간이 걸리는 알고리즘으로는
    시간안에 해결하기 힘듭니다.
    
    
    분할정복



"""


import time
import random

# 완전탐색을 이용한 잘라낸 최대 판자의 크기
def bruteForce(fences):
    result = 0

    for left in range(len(fences)):
        minHeight = fences[left]
        
        for right in range(left,len(fences)):
            minHeight = min(minHeight,fences[right])
            result = max(result, (right-left + 1) * minHeight)
    
    return result

# 분할정복을 이용한 최대 판자의 크기
# fences : 각 판자들의 높이
def divideNConquer(fences, left, right):
    if left == right : return fences[left]

    mid = (left + right) // 2
    result = max(divideNConquer(fences,left,mid),divideNConquer(fences,mid+1,right))

    lo,hi = mid,mid+1
    height = min(fences[lo],fences[hi])
    
    result = max(result,height*2)

    while left < lo or hi < right:
        if hi < right and (lo == left or fences[lo-1] < fences[hi+1]):
            hi = hi + 1
            height = min(height,fences[hi])
        else:
            lo = lo - 1
            height = min(height,fences[lo])

        result = max(result,height * (hi-lo + 1))

    return result

# sweeping 기법을 이용한 최대 판자의 크기
def sweeping(fences):
    fencenum = len(fences)  # 판자 수
    fences.append(0)  # 스택의 마지막 요소까지 처리해 줘야 하므로 넣음
    fencestack = []  # 스택 역할을 할 리스트
    result = 0
    width = 0  # 너비
    for j in range(fencenum+1):
        while fencestack and fences[fencestack[-1]] >= fences[j]:  # 스택이 비지 않고, 스택에 저장된 위치의 높이가 현재 높이보다 크다면
            position = fencestack.pop()
            if not fencestack:  # 스택이 비었다면
                width = j
            else:  # 안 비었다면
                width = j - fencestack[-1] - 1
            area = width * fences[position]  # 너비*높이
            result = max(result, area)  # 최대값을 구한다
        fencestack.append(j)
    
    return result

# n : 울타리의 수
def getFences(n):
    return [random.randint(1,10000) for i in range(n)]

if __name__=="__main__":
    n = random.randint(1,20000)
    fences = getFences(n)

    print("n : ",n)

    start = time.time()
    result = bruteForce(fences)
    print("bruteforec time : ",time.time()-start)
    print("넓이 : ",result)

    start = time.time()
    result = divideNConquer(fences,0,len(fences)-1)
    print("divide&conquer time : ",time.time()-start)
    print("넓이 : ",result)

    start = time.time()
    result = sweeping(fences)
    print("sweeping time : ",time.time()-start)
    print("넓이 : ",result)