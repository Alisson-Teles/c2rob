#include<stdio.h>
#include<string.h>
unsigned long long m,a;
int main(){
  long long i,j,r,n,min,d[2][50]={0};
  char s[50],c[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  while(scanf("%lld %s",&n,s),n){
    j=n;
    m=0;
    for(i=r=0;i<40;i++)d[0][i]=0;
    min=2*1e18;
    for(i=2;i<=j;i++){
      if(j%i==0)r++;
      else continue;
      d[1][r]=i;
      while(j%i==0){
	j/=i;
	d[0][r]++;
      }
    }//printf("a\n");
    for(i=1;i<=r;i++)printf("%lld %lld\n",d[1][i],d[0][i]);
    for(i=0;s[i];i++){
      m*=n;
      for(j=0;c[j]-s[i];j++);
      m+=j;
    }//printf("%lld\n",m);
    for(i=1;i<=r;i++){
      a=0;
      for(j=d[1][i];j<=m;j*=d[1][i])a+=m/j;
      a/=d[0][i];//printf("%lld %lld\n",i,a);
      if(min>a)min=a;
    }
  
  printf("%lld\n",min);
  }
  return 0;
}
      