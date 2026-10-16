#include <stdio.h>

int main(){
    int N,ans=0;
    scanf("%d",&N);
    int B[N-1];
    for(int i=0;i<N-1;i++){
        scanf("%d",&B[i]);
    }
    if(N>2){
        for(int i=0;i<N-1;i++){
            if((B[i]>B[i+1])&&(i<N-2)){
                ans+=B[i+1];
            }
            if((B[i]<=B[i+1])&&(i<N-2)){
                ans+=B[i];
            }
        }
    }
    ans+=B[0];
    ans+=B[N-2];
    printf("%d",ans);
    return 0;
}