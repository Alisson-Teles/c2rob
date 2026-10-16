#include <stdio.h>

int osero(int c,int d, int e, int f){

  int a = c -e;
  int b = d - f;

  printf("%d\n", a * b);

return 0;
}

int main(){
 int H,W,h,w;

  scanf("%d %d",&H,&W);
  scanf("%d %d",&h,&w);

  osero(H,W,h,w);

  return 0;

}