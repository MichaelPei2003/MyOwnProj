#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int min,max;
    double c,f;
    scanf("%d%d",&min,&max);
    printf("fahr celsius\n");
    if(max>100)
    {
        printf("Invalid.");
    }
    else if(min>max)
    {
        printf("Invalid.");
    }
    else
    {
        for(;min<=max;)
        {
            c=(double)(min-32)*5/9;
            printf("%d%6.1lf",min,c);
            if(min+2<=max)
            {
                printf("\n");
            }
            min=min+2;
        }
    }
}
