#include <stdio.h>
#include <string.h>

int LENGTH = 100000;

void reverse(char *s) {
  int len = strlen(s);
  
  for (int i=0; i < len / 2; i ++) {
    char t = s[i];
    s[i] = s[len - 1 - i];
    s[len - 1 -i] =t;
  }
}

int main(void) {

  char S[LENGTH+1];
  char s[4][8] = {"dream","dreamer","erase","eraser"};
  scanf("%s",S);

  int len = strlen(S);
  int t = 0;
  int k = -1;

  for (int i = 0; i < 4; i++) {
    reverse(s[i]);
  }
  reverse(S);

    while (t < len) {
      for (int i=0;i < 4; i++) {
        if (!strncmp(S+t,s[i],strlen(s[i]))) {
          k = strlen(s[i]);
          break;
        }
      }
      if ( k < 0 ) {
        printf("NO");
        return 0;
      }
      t += k;
    }
    printf("YES");
    return 0;
}