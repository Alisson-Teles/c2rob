#include<stdio.h>
int main(void){
    int n,q,i,flag,a[100000],time=0;
    char s[100000][11];
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++){
        scanf("%s %d",s[i],&a[i]);
    }

    flag=1;
    while(flag){
	flag=0;
	for(i=0;i<n;i++){
	    if(a[i]>q){
		flag=1;
		time+=q;
		a[i]-=q;
	    }else if(a[i]>0){
		time+=a[i];
		a[i]=0;
		printf("%s %d\n",s[i],time);
	    }
	}
    }

    return 0;
}