#include <stdio.h>
#include <stdlib.h>

int p[100];

struct queen{
    int data;
    struct queen *next;
};

int Menu()
{
    printf("*****************˳��ջ��������ϵͳ*****************\n");
    printf("* 1.����˳��ջ                2.��ʾ˳��ջ         *\n");
    printf("* 3.��ջ                      4.��ջ               *\n");
    printf("* 5.����ջ��Ԫ��              6.�ÿ�˳��ջ         *\n");
    printf("* 7.��������                  8.����ת��           *\n");
    printf("* 9.���ֻ�������              10.����ƥ������      *\n");
    printf("* 11.��ŵ������               12.���ʽ��ֵ        *\n");
    printf("* 13.��������                 14.�ʺ�����          *\n");
    printf("* 15.�Թ�����                 16.�˳�              *\n");
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
