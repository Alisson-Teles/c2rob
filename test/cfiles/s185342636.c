#include<stdio.h>

int main(){
	
int nm[101][101]={0},ml[101][101]={0},n,m,l,i,j,k;
long nl[101][101]={0};

scanf("%d %d %d",&n,&m,&l);
for(j=0;j<n;j++){
	for(i=0;i<m;i++){
		scanf("%d",&nm[j][i]);
	}
}

for(j=0;j<m;j++){
	for(i=0;i<l;i++){
		scanf("%d",&ml[j][i]);
	}
}

 for(j=0;j<n;j++) {
                for(i=0;i<l;i++) {
                        for(k=0;k<m;k++) {
                                nl[j][i]+=nm[j][k]*ml[k][i];
                        }
                        printf("%ld", nl[j][i]);
                        if(i!=l-1)      printf(" ");
                }
                printf("\n");
        }

return 0;

}