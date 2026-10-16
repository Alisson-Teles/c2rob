#include <stdio.h>

int main (void){
  int H,W,h,w;

  while(1){
    scanf("%d %d",&H,&W);
    if(H == 0 && W == 0){
      break;
    }

    for(h=0; h<H; h++){
      for(w=0; w<W; w++){
        if(w == 0 || h == 0 || w == (W-1) || h == (H-1)){
        printf("#");
      }else{
        printf(".");
      }
    }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
