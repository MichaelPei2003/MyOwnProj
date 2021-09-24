#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d",&n);
    if(n<0){printf("sign(%d) = -1",n);}
    if(n==0){printf("sign(0) = 0");}
    if(n>0){printf("sign(%d) = 1",n);}
}
