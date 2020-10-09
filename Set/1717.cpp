#include <stdio.h>

int set[1000001];
int n, m;

void makeSet(int x){
    set[x] = x;
}

int findSet(int x){
    if (x == set[x]){
        return x;
    }
    else{
        return set[x] = findSet(set[x]);
    }
}

void _union(int x, int y){
    set[findSet(y)] = findSet(x);
}

int main(){
    scanf("%d %d",&n,&m);

    int c,x,y;

    for(int i=0; i<=n; i++){
        makeSet(i);
    }

    for(int i=0; i<m; i++){
        scanf("%d %d %d",&c,&x,&y);

        switch (c)
        {
        case 0:
            _union(x,y);
            break;
        case 1:
            if(findSet(x) == findSet(y)){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
            break; 
        }
    }
}