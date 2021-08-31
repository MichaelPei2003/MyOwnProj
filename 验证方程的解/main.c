#include <stdio.h>

int main(void)
{
    int x,y,z,i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(x*x+y*y+z*z==3*x*y*z)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
