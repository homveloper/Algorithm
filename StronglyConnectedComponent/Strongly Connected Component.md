# SCC

방향 그래픙서 어떤 그룹 X에 있는 임의의 두 정점 A,B에 대해서 항상 A->B로 가는 경로가 존재한다면 그 그룹을 SCC(Strongly Conntected 
Components)라 한다. SCC는 다음 두 조건을 만족합니다.

- 같은 SCC 내의 임의의 두 정점 A,B 사이의 경로가 항상 존재한다.
- 서로 다른 SCC에서 뽑은 임의의 두 점 A,B 사이의 경로 A->B로 가는 경로와 B->A로 가는 경로는 동시에 존재할 수 없다. 즉, 사이클이 존재할 수 없다.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e1/Scc-1.svg/220px-Scc-1.svg.png)

어떤 정점들이 서로 SCC를 이루는지 분류하는 알고리즘은 DFS 기반으로 동작합니다. 

## 코사주 알고리즘

코사주 알고리즘은 주어지는 방향 그래프와 방향을 뒤집은 역 방향 그래프가 필요합니다. 

1. 정방향 그래프에 DFS를 수행하여, 끝나는 순서대로 스택에 삽입
2. 스택에서 Pop 하는 순서대로 역방향 DFS를 수행하여 한번 수행에 탐색되는 모든 정점들을 같은 SCC로 묶음
3. 스택이 빌때 까지 2번 작업을 반복



## 