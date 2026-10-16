#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NODE_NUM 100


int dis[NODE_NUM + 1];
int ans[NODE_NUM + 1];
int mtx[NODE_NUM + 1][NODE_NUM + 1];
int flag[NODE_NUM + 1];


void search(int node_idx, int d, int node_num){
    
    int i;
    
    if (flag[node_idx] == 1) {
        return;
    }
    
    for (i=1; i <= node_num; i++) {
        if
            (mtx[node_idx][i] != -1
            &&
            !flag[i]
            &&
            dis[i] > d + mtx[node_idx][i]
            )
        {
            dis[i] = d + mtx[node_idx][i];
            ans[i] = mtx[node_idx][i];
        }
        
        if (mtx[node_idx][i] != -1 && !flag[i]) {
            flag[node_idx] = 1;
            search(i, dis[i], node_num);
            flag[node_idx] = 0;
        }
    }
    return;

}


int main( ){
    
    int i, j, n, rtn;
    rtn = 0;
    scanf("%d", &n);
    
    for (i=1; i<=n; i++) {
        for (j = 1; j <=n; j++) {
            scanf("%d", &(mtx[i][j]));
        }
    }
    
    for (i = 1; i <=n; i++) {
        dis[i] = 200000000;
    }
    
    search(1, 0, n);
    
    for (i = 2; i <=n; i++) {
        rtn += ans[i];
    }
    
    printf("%d\n", rtn);
    
    return 0;
}