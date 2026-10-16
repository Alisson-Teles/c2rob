#include<stdio.h>

#define N 100

int main(){
int A[N][N];
int B[N]={},C[N];
int i,j,c,n;
int m1,m2,min;
int sum=0;

for(i=0;i<100000;i++)
    C[i]=100;

scanf("%d",&n);

for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        scanf("%d",&A[i][j]);

B[0]=0;
m2=1;

while(1){
c=0;
for(i=0;i<n;i++)
    if(B[i]==1)c++;
   if(c==n)break;

m1=2000;

for(i=0;i<n;i++){
if(C[i]>A[m2][i]&& B[i]!=1&&A[m2][i]!=-1)
B[i]=A[m2][i];
if(B[i]!=1&&m1>C[i]){
min=i;
m1=C[i];
}
}
sum=sum+m1;
C[min]=m1;
B[min]=1;
m2=min;
}
printf("%d\n",sum);

return 0;
}