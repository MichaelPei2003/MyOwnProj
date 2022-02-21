#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    FILE *fp=fopen("file.txt","r+");
    char b[1024];
    while(!feof)
    {
        fgets(b,1024,fp);
    }
    printf("%s",b);
    fclose(fp);
}
