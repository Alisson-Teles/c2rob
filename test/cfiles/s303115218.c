#include<stdio.h>
int main(){   
	int i,x,ans,a;
	while(scanf("%d",&x)!=EOF){
		ans=0;
		a=600/x;
		for(i=1;i<=a;i++){
			ans+=x*(x*i)*(x*i);
		}
		printf("%d\n",ans);
	return 0;
	}
}