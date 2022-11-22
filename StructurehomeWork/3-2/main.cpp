#include<bits/stdc++.h>

using namespace std;

int main()
{
    char a[1000],s[20];
    scanf("%s",a);
    int l=strlen(a);
    int k=0,sp=-1;
    for(int i=0; i<l; i++)
    {
        if(a[i]>='0'&&a[i]<='9'||a[i]=='.')//数字或者小数点 直接输出
        {
            if(k)printf(" ");
            k=1;
            while(a[i]>='0'&&a[i]<='9'||a[i]=='.')
                printf("%c",a[i++]);
            i--;
        }
        else//符号
        {
            if(a[i]=='(')s[++sp]=a[i];//左括号直接进栈
            else if(a[i]=='*'||a[i]=='/')//乘除优先级最大 先输出栈顶符号 再入栈
            {
                while(s[sp]=='*'||s[sp]=='/'&&sp!=-1)
                    printf(" %c",s[sp--]);
                s[++sp]=a[i];
            }
            else if(a[i]==')')//输出直到遇到左括号停止
            {
                while(s[sp]!='(')
                    printf(" %c",s[sp--]);
                sp--;
            }
            else if(a[i]=='+'||a[i]=='-')
            {
                if(a[i-1]>='0'&&a[i-1]<='9'||a[i-1]==')')
                {
                    while(s[sp]!='('&&sp!=-1)//遇到符号除了左括号直接输出
                        printf(" %c",s[sp--]);
                    s[++sp]=a[i];
                }
                else
                {
                    if(k==0)
                        printf("%c",a[i]);
                    else
                    {
                        printf(" ");
                        if(a[i]!='+')
                            printf("%c",a[i]);
                    }

                    k=0;
                }

            }
        }
    }
    while(sp!=-1)//栈内按顺序输出
        printf(" %c",s[sp--]);
    return 0;
}

