#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x,y;
    char n;
    scanf("%d %c %d",&x,&n,&y);
    switch(n)
    {
        case '+':printf("%d",x+y);break;
        case '-':printf("%d",x-y);break;
        case '*':printf("%d",x*y);break;
        case '/':if(y==0) printf("ERROR");else printf("%d",x/y);break;
        case '%':if(y==0) printf("ERROR");else printf("%d",x%y);break;
        default :printf("ERROR");
    }
}
