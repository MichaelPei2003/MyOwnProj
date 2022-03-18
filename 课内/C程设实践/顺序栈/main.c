#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int length, i, j;
struct List stack;
int cnt;

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

void Show()
{
    int cnt=0;
    struct Node *tmp=stack.pHead;
    while(tmp->next)
    {
        tmp=tmp->next;
        printf("%-5d",tmp->data);
        cnt++;
        if(cnt%10==0)
        {
            printf("\n");
        }
    }
    printf("\n\n");
    Menu();
}

void Create()
{
    int n;
    printf("Please enter required length: ");
    scanf("%d",&length);
    stack.pHead=(struct Node*)malloc(sizeof(struct Node));
    stack.pHead->next=NULL;
    struct Node *tmp=stack.pHead;
    for(i=0; i<length; i++)
    {
        static unsigned int seed = 0;
        seed++;
        srand((unsigned) time(NULL) + seed * seed);
        struct Node *s=(struct Node*)malloc(sizeof(struct Node));
        if(s==NULL)
        {
            printf("Operation failed!");
        }
        n=rand()%100;
        if(n==0)
        {
            i--;
            continue;
        }
        s->data=n;
        s->next=NULL;
        tmp->next=s;
        tmp=tmp->next;
    }
    printf("Stack created!\n");
    Show();
    Menu();
}

void Push()
{
    int push;
    printf("Value?\nPlease enter:");
    scanf("%d",&push);
    struct Node *s=(struct Node*)malloc(sizeof(struct Node));
    s->data=push;
    struct Node *tmp=stack.pHead;
    s->next=tmp->next;
    stack.pHead->next=s;
    Show();
    Menu();
}

void Pop()
{
    int pop;
    struct Node *s=stack.pHead->next;
    stack.pHead->next=s->next;
    free(s);
    Show();
    Menu();
}

void GetTop()
{

}

void Clear()
{
    ClearList();
    Menu();
}

void ClearList()
{
    struct Node *p=stack.pHead->next;
    while(p!=NULL)
    {
        struct Node *q=p;
        p=p->next;
        free(q);
    }
    stack.pHead=NULL;
    free(stack.pHead);
    stack.pHead=NULL;
    printf("Stack Cleared!");
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
    int num;
    cnt=0;
    printf("Please enter number of plates:");
    scanf("%d", &num);
    HanoiOperation(num, 'A', 'B', 'C');
    printf("Total steps are %d", cnt);
    Menu();
}

void GetValue()
{

}

void Backpack()
{
    stack.pHead=(struct Node*)malloc(sizeof(struct Node));
    stack.pHead->next=NULL;
    struct Node *tmp=stack.pHead;
}

void Queens()
{

}

void Maze()
{

}

void HanoiOperation(int n, char x, char y, char z)
{
    if(n==1)
    {
        cnt++;
        printf("Step%d: Move from %c to %c\n", cnt, x, z);
    }
    else
    {
        HanoiOperation(n-1, x, z, y);
        cnt++;
        printf("Step%d: Move from %c to %c\n", cnt, x, z);
        HanoiOperation(n-1, y, x, z);
    }
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
