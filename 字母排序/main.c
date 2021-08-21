#include <stdio.h>

int main(void)
{
    char a,b,c,d,e,f;
    scanf("%c %c %c",&a,&b,&c);
    if (a>b)
        {
             if (a>c)
             {
                 d=a;
                 if(b>c)
                 {
                     e=b;
                     f=c;
                 }
                 else
                 {
                     e=c;
                     f=b;
                 }
             }
             else
             {
                 d=c;
                 e=a;
                 f=b;
             }
        }
    else
        {
            if (b>c)
            {
                d=b;
                if(c>a)
                {
                    e=c;
                    f=a;
                }
                else
                {
                    e=a;
                    f=c;
                }
            }
            else
            {
                d=c;
                if(a>c)
                {
                    e=a;
                    f=c;
                }
                else
                {
                    e=c;
                    f=a;
                }
            }

        }
        printf("The sorted characters are: %c %c %c",f,e,d);
}
