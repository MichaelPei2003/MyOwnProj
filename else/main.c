#include <stdio.h>
#include <stdlib.h>
#include   int main() {     int t;     if (scanf("%d", &t) == 1) {         printf("%d", t);     } else {         printf("Failed to read integer.\n");     }     return 0; }
int main()
{
    int a;
    scanf("%d",&a);
    if (a<=10)
    {
        printf("%d<=10",a);

    }
    else
    {
        printf("%d>10",a);
    }
    return 0;
}
