#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i,l,r;
    scanf("%d %d %d", &l,&r,&i);
    int ans=(r/i)-(l/i);
    if(l%i==0){ans++;}
    printf("%d",ans);
}