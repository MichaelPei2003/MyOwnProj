#include <stdio.h>
int main(void)
{
    int m,t,s,n;
    scanf("%d%d%d",&m,&t,&s);
    if(t==0){n=0;}
    else if(s%t==0){n=m-s/t;}
    else{n=m-s/t-1;}
    if(n<0){n=0;}
    printf("%d",n);
}
