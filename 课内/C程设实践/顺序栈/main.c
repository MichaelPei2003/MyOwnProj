#include <stdio.h>
#include <stdlib.h>

int p[100];

struct queen{
    int data;
    struct queen *next;
};

int Menu()
{
    printf("*****************顺序栈基本操作系统*****************\n");
    printf("* 1.创建顺序栈                2.显示顺序栈         *\n");
    printf("* 3.入栈                      4.出栈               *\n");
    printf("* 5.返回栈顶元素              6.置空顺序栈         *\n");
    printf("* 7.回文问题                  8.数制转换           *\n");
    printf("* 9.数字回文问题              10.括号匹配问题      *\n");
    printf("* 11.汉诺塔问题               12.表达式求值        *\n");
    printf("* 13.背包问题                 14.皇后问题          *\n");
    printf("* 15.迷宫问题                 16.退出              *\n");
    printf("*                                                  *\n");
    printf("****************************************************\n\n");
    printf("Please Enter:");
    int tmp;
    scanf("%d", &tmp);
    Switch(tmp);
}

void Create()
{
    printf("Please enter required length: ");

}

void Show()
{

}

void Push()
{

}

void Pop()
{

}

void GetTop()
{

}

void Clear()
{

}

void Palindrome()
{

}

void NumConvert()
{

}

void  PalindromeNum()
{

}

void Match()
{

}

void Hanoi()
{

}

void GetValue()
{

}

void Backpack()
{

}

void Queens()
{

}

void Maze()
{

}

void Switch(int imput)
{
    switch(imput)
    {
    case 1:
        Create();
    case 2:
        Show();
    case 3:
        Push();
    case 4:
        Pop();
    case 5:
        GetTop();
    case 6:
        Clear();
    case 7:
        Palindrome();
    case 8:
        NumConvert();
    case 9:
        PalindromeNum();
    case 10:
        Match();
    case 11:
        Hanoi();
    case 12:
        GetValue();
    case 13:
        Backpack();
    case 14:
        Queens();
    case 15:
        Maze();
    case 16:
        exit(0);
    }
}

int main()
{
    Menu();
}
