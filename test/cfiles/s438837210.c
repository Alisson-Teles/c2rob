#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void){
char ch[100],ch2[10000000],ch3[]="END_OF_TEXT";
int count=0,i;

scanf("%s",ch);

for(i=0;i<strlen(ch);i++)
ch[i]=tolower(ch[i]);

while(1){

scanf("%s",ch2);

if(strcmp(ch2,ch3)==0)break;

for(i=0;i<strlen(ch2);i++)
ch2[i]=tolower(ch2[i]);

if(strcmp(ch,ch2)==0)count++;

}
printf("%d\n",count);

return 0;
}