'''

주어진 N에 대해서 N-1 곳 중에서  0~N-1개의 핀을 지정했을 때
발생하는 경우가 적합한지 확인하고 갯수를 카운팅 하면 된다.

예를 들어 4의 경우 

0개의 핀을 지정하면 4가 되지만 
1,2,3 중에 포함되지 않으므로 넘어간다.

| | | |

1개의 핀을 지정하면 아래와 같이 되고
모든 경우 다 적합하므로 +3이 된다.

| ^ | | |   1, 3
| | ^ | |   2, 2
| | | ^ |   3, 1

| ^ | ^ | |
| ^ | | ^ |
| | ^ | ^ |

^ | | | ^ |

|^|||
||^||
|||^|
|^|^||^
|^||^|^
||^|^|^
|^||^|
|^|||^
||^|^|
|||^|^

초기 조건 nP1 = n
점화식 nPr = n * (n-1)P(r-1)
'''

from itertools import combinations

T = int(input())

for _ in range(T):
    N = int(input())
    IDX = [i for i in range(1,N)]
    result = 1 if 1<=N<=3 else 0

    for i in range(1,N):
        idx_list = list(combinations(IDX, i))
        for j in idx_list[0:]:
            previous = 0
            flag = True

            for k, idx in enumerate(j):
                if 1<= idx - previous <= 3:
                    previous = idx
                else:
                    flag = False
                    break

            if flag and 1<=N - previous<=3:
                result +=1 
        
    print(result)