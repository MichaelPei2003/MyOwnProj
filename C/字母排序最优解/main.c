#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char a,b,c,t;
    t=0;
    scanf("%c %c %c",&a,&b,&c);
    if(a<b){t=a;a=b;b=t;}
    if(a<c){t=a;a=c;c=t;}
    if(b<c){t=b;b=c;c=t;}
    printf("%c>%c>%c",a,b,c);
}
