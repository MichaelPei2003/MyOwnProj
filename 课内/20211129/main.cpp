#include <bits/stdc++.h>
#define MAXLINE 100

using namespace std;

/*void encrypt(char*s)
{
    for(; *s!='\0'; s++)
    {
        if(*s=='z')
        {
            *s='a';
        }
        else
        {
            *s=*s+1;
        }
    }
}

int main(void)
{
    char line[MAXLINE]={};
    printf(" ‰»Î◊÷∑˚¥Æ:");
    gets(line);
    encrypt(line);
    printf("%s %s","º”√‹∫Û:",line);
}
*/

int atoi(char *c)
{
    int tmp=0;
    for(int j=0;c[j]!='\0';j++)
    {
        tmp=tmp*10+c[j]-'0';
    }
    return tmp;
}

//int main(int argc,char *argv[])
int main()
{
    int sum=0;
    char *argv[5]={"2","2","2"};
    int argc=3;
    for(int i=1;i<argc;i++)
    {
        sum+=atoi(argv[i]);
    }
    printf("%d",sum);
    return 0;
}
