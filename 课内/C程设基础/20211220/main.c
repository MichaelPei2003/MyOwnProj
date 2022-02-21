#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum weekday {sun,mon,tue,wed,thu,fri,sat};
    enum weekday w,week,s[100],*pweek;
    printf("输入一个介于1-7之间的数");
    scanf("%d",w);
    switch(w)
    {
        case 1:printf("Monday");
        case 2:printf("Tuesday");
        case 3:printf("Wednesday");
    }
}
