
# n : 전체 원소 수
# m : 앞으로 선택할 원소 수
# picked : 지금 까지 선택한 원소들의 번호
# 기능 : n개의 원소 중 m개를 고르는 모든 조합
def combination(picked, n, m):
    if(m == 0):
        print(picked)
        return 

    smallest = 0 if len(picked)<=0 else picked[-1] + 1

    for i in range(smallest,n):
        picked.insert(len(picked),i)
        combination(picked,n,m-1)
        picked.pop()

picked = []
combination(picked,3,2)