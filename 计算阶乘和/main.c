#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x,y,n,s;
    n=0;s=0;y=1;
    scanf("%d",&x);
    for(;x>0;x--)
    {
        n=x;
        for(;n>0;n--)
        {
            y=n*y;
        }
        s=s+y;
        y=1;
    }
    printf("%d",s);
}
