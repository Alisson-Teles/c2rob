#include<stdio.h>

int main(){
  int c, n, cnt = 0, flag = 0, d, r ,tmp;
  int i, j, k, pri[128][128];
  char kind[128];

  scanf("%d%d", &c, &n);
  
  for(i=0; i<n; i++){
    scanf("%s", kind);
    for(j=0; j<n; j++){
      if(kind[j]=='0'){
	pri[i][j]=0;
      }else{
	pri[i][j]=1;
      }
    }
  }

  /* for(i=0; i<n; i++){ */
  /*   for(j=0; j<n; j++){ */
  /*     printf("%d ", pri[i][j]); */
  /*   } */
  /*   printf("\n"); */
  /* } */


  
  for(i = 0; i < n; i++){   /* テ・ツッツセテァツァツーテヲツ?ァ */
    for(j = 0; j < n/2; j++){
      if(pri[i][j] != pri[i][n - 1 - j]) flag = 1; break;
      if(pri[j][i] != pri[n - 1 - j][i]) flag = 1; break;
    }
  }
  
  if(flag == 0) cnt++;


  if(c == 1){
    printf("%d\n", cnt);
  }

  else{
    
    tmp=c-1;
    for(k = 0; k < tmp; k++){  /* テ」ツδ?」ツつァテ」ツδウテ」ツつクテ、ツサツ・テゥツ卍催ゥツ鳴凝・ツァツ?*/ 
      scanf("%d", &d);   /* テ」ツδ?」ツつァテ」ツδウテ」ツつク */
      for(i = 0; i < d; i++){
	scanf("%d%d", &c, &r);
	if(pri[c - 1][r - 1] == 0) pri[c - 1][r - 1] = 1;
	else pri[c - 1][r - 1] = 0;
      }

      flag = 0;  /* テ・ツッツセテァツァツーテヲツ?ァ */
      for(i = 0; i < n; i++){  
	for(j = 0; j < n/2; j++){
	  if(pri[i][j] != pri[i][n - 1 - j]) flag = 1; break;
	  if(pri[j][i] != pri[n - 1 - j][i]) flag = 1; break;
	}
      }
    
      /* for(i=0; i<n; i++){ */
      /*   for(j=0; j<n; j++){ */
      /* 	printf("%d ", pri[i][j]); */
      /*   } */
      /*   printf("\n"); */
      /* } */
   
      if(flag == 0) cnt++;

    }

    printf("%d\n", cnt);

  }
  
  return 0;
}