#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum weekday {sun,mon,tue,wed,thu,fri,sat};
    enum weekday w,week,s[100],*pweek;
    printf("����һ������1-7֮�����");
    scanf("%d",w);
    switch(w)
    {
        case 1:printf("Monday");
        case 2:printf("Tuesday");
        case 3:printf("Wednesday");
    }
}
