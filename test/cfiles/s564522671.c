#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        __int64 sum=1;
        for(i=1;i<=n;i++)
        {
            sum=(i*sum)%1000000007;
        }
            printf("%I64d\n",sum);
    }
    return 0;
}
