#include <stdio.h>
int main(void)
{
    int N,T,A;
    double res;
    int H[1100];
    scanf("%d%d%d", &N, &T, &A);
    for(int i=0;i<N;i++) scanf("%d", &H[i]);
    int min=100000;
    int ans=0;
    for(int i=0;i<N;i++){
        res=((T-H[i]*0.006)-A)*((T-H[i]*0.006)-A);
        if(min>res){
            min=res;
            ans=i+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
