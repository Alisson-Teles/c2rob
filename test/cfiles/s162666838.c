#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
  int W, H, x, y;
  long double max = 0;
  int ans = 0;

  scanf("%d%d%d%d", &W, &H, &x, &y);

  if(x > y){
    max = W * y;
    if(W > H){
      if(max < (W - x) * H){
	max = (W - x) * H;
      }
    }
  }else{
    max = H * x;
    if(H > W){
      if(max < (H - y) * W){
	max = (H - y) * W;
      }
    }
  }
  if(W == H){
    ans = 1;
  }
  if((x == 0 && y == 0) || (x == 0 && y == H) || (x == W && y == 0) || (x == W && y == H)){
    //    max = (W * H) / 2;
    ans = 0;
  }
  max = (W * H) / 2;

  printf("%.11Lf %d", max, ans);
  printf("\n");

}
