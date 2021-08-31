#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a,b,c,d,e,n,r;
    a=0;b=0;c=0;d=0;e=0;
    scanf("%d",&n);
    for(;n>0;)
    {
         scanf("%d",&r);
         n=n-1;
         if(r>=90){a++;}
         else if(r>=80){b++;}
         else if(r>=70){c++;}
         else if(r>=60){d++;}
         else{e++;}
    }
    printf("%d %d %d %d %d",a,b,c,d,e);
}
